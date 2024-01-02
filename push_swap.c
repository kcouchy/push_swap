/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/01/02 16:16:35 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a_stack)
{
	if (ft_check_list(*a_stack) == 0)
		return ;
	if ((*a_stack)->num > (*a_stack)->next->num)
		ft_sa_sb(*a_stack, 'a');
	if (ft_check_list(*a_stack) == 0)
		return ;
	if ((ft_lstsize(*a_stack) == 3) && ((*a_stack)->next->num > (*a_stack)
			->next->next->num))
	{
		ft_rra_rrb(a_stack, 'a');
		if ((*a_stack)->num > (*a_stack)->next->num)
			ft_sa_sb(*a_stack, 'a');
	}
	return ;
}

void	ft_simple_sort(t_list **a_stack, t_list **b_stack, int argc)
{
	int	list_len;

	list_len = argc;
	while (list_len > 3)
	{
		if ((*a_stack)->index < (argc - 3))
			ft_pa_pb(a_stack, b_stack, 'b');
		else
			ft_ra_rb(a_stack, 'a');
		list_len = ft_lstsize(*a_stack);
	}
	ft_sort_3(a_stack);
	quicksort_b2a(a_stack, b_stack);
	return ;
}

void	quicksort_a2b(t_list **a_stack, t_list **b_stack, int a_size)
{
	int	chunk;
	int	it_chunk;

	chunk = a_size * 0.13;
	if (a_size > 250)
		chunk = a_size * 0.05;
	it_chunk = chunk;
	while (a_size > 1)
	{
		while (a_size > 0)
		{
			if ((*a_stack)->index < chunk + it_chunk)
			{
				ft_pa_pb(a_stack, b_stack, 'b');
				if ((*b_stack)->index < chunk)
					ft_ra_rb(b_stack, 'b');
			}
			else
				ft_ra_rb(a_stack, 'a');
			a_size--;
		}
		chunk += it_chunk + it_chunk;
		a_size = ft_lstsize(*a_stack);
	}
}

void	quicksort_b2a(t_list **a_stack, t_list **b_stack)
{
	int		b_stack_size;
	int		a_stack_size;
	int		closest;

	a_stack_size = ft_lstsize(*a_stack);
	if (a_stack_size == 0)
		ft_big2a(a_stack, b_stack);
	b_stack_size = ft_lstsize(*b_stack);
	while (b_stack_size > 0)
	{
		closest = ft_closest(*a_stack, (*b_stack)->index);
		a_stack_size = ft_lstsize(*a_stack);
		ft_turny(a_stack, 'a', closest, a_stack_size);
		ft_pa_pb(b_stack, a_stack, 'a');
		b_stack_size--;
	}
	a_stack_size = ft_lstsize(*a_stack);
	closest = ft_closest(*a_stack, -1);
	ft_turny(a_stack, 'a', closest, a_stack_size);
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		a_size;

	if (argc < 2)
		return (0);
	if (ft_checkinputs(argc, argv) == 1)
		return (ft_error());
	if (argc == 2)
		return (0);
	a_stack = ft_makelist(argc, argv);
	if (!a_stack)
		return (ft_error());
	b_stack = NULL;
	if (ft_check_list(a_stack) == 0)
		return (0);
	if (argc <= 11)
		return (ft_simple_sort(&a_stack, &b_stack, argc - 1), 0);
	a_size = ft_lstsize(a_stack);
	quicksort_a2b(&a_stack, &b_stack, a_size);
	quicksort_b2a(&a_stack, &b_stack);
	ft_lstclear(&a_stack);
	return (0);
}
