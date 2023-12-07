/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/07 11:24:18 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_tests(t_list *a_stack, t_list *b_stack)
// {
// 	ft_printf("\n///test ft_sa_sb:///\n");
// 	print_list(a_stack);
// 	ft_sa_sb(a_stack, 'a');
// 	print_list(a_stack);

// 	ft_printf("\n///test ft_pa_pb:///\n");
// 	print_list(a_stack);
// 	print_list(b_stack);
// 	ft_pa_pb(&a_stack, &b_stack, 'b');
// 	print_list(a_stack);
// 	print_list(b_stack);
// 	ft_pa_pb(&b_stack, &a_stack, 'a');
// 	print_list(a_stack);
// 	print_list(b_stack);

// 	ft_printf("\n///test ft_ra_rb:///\n");
// 	print_list(a_stack);
// 	ft_ra_rb(&a_stack, 'a');
// 	print_list(a_stack);

// 	ft_printf("\n///test ft_rra_rrb:///\n");
// 	print_list(a_stack);
// 	ft_rra_rrb(&a_stack, 'a');
// 	print_list(a_stack);
// 	ft_pa_pb(&a_stack, &b_stack, 'b');
// 	ft_pa_pb(&a_stack, &b_stack, 'b');
// 	ft_pa_pb(&a_stack, &b_stack, 'b');

// 	ft_printf("\n///test ft_ss:///\n");
// 	print_list(a_stack);
// 	print_list(b_stack);
// 	ft_ss(a_stack, b_stack);
// 	print_list(a_stack);
// 	print_list(b_stack);

// 	ft_printf("\n///test ft_rr:///\n");
// 	print_list(a_stack);
// 	print_list(b_stack);
// 	ft_rr(&a_stack, &b_stack);
// 	print_list(a_stack);
// 	print_list(b_stack);

// 	ft_printf("\n///test ft_rrr:///\n");
// 	print_list(a_stack);
// 	print_list(b_stack);
// 	ft_rrr(&a_stack, &b_stack);
// 	print_list(a_stack);
// 	print_list(b_stack);
	
// 	ft_lstclear(&a_stack);
// 	ft_lstclear(&b_stack);
// }

void	ft_simple_sort(t_list *a_stack)
{
	int	i;

	i = 0;
	if (a_stack->num > a_stack->next->num)
		ft_sa_sb(a_stack, 'a');
	if ((ft_lstsize(a_stack) == 3) && 
		(a_stack->next->num > a_stack->next->next->num))
	{
		ft_rra_rrb(&a_stack, 'a');
		if (a_stack->num > a_stack->next->num)
				ft_sa_sb(a_stack, 'a');
	}
	return;
}

int		ft_depth(t_list *b_stack, int num)
{
	int	depth;

	depth = 0;
	while (b_stack)
	{
		if (b_stack->num == num)
			break ;
		b_stack = b_stack->next;
		depth++;
	}
	return (depth);
}

void	quicksort_a2b(t_list **a_stack, t_list **b_stack)
{
	int	pivot;
	int	a_list_len;

	a_list_len = ft_lstsize(*a_stack);
	while(a_list_len > 2)
	{
		pivot = ft_findpivot(*a_stack);
		while (a_list_len > 0)
		{
			if ((*a_stack)->num < pivot)
				ft_pa_pb(a_stack, b_stack, 'b');
			else
				ft_ra_rb(a_stack, 'a');
			a_list_len--;
		}
		a_list_len = ft_lstsize(*a_stack);
	}
	ft_pa_pb(a_stack, b_stack, 'b');
	ft_pa_pb(a_stack, b_stack, 'b');
	return ;
}

void	quicksort_b2a(t_list **a_stack, t_list **b_stack, t_list **b_sort)
{
	t_list	*last_b;
	int		b_stack_size;
	int		depth;
	int		rdepth;

	b_stack_size = ft_lstsize(*b_stack);
	while (b_stack_size > 0)
	{
		if (ft_lstsize(*b_stack) == 1)
		{
			ft_pa_pb(b_stack, a_stack, 'a');
			break;
		}
		if (ft_lstsize(*b_stack) == 2)
		{
			if ((*b_stack)->num > (*b_stack)->next->num)
				ft_sa_sb(*b_stack, 'b');
			ft_pa_pb(b_stack, a_stack, 'a');
			break;
		}
		last_b = ft_lstlast(*b_sort);
		depth = ft_depth(*b_stack, last_b->num);
		if (depth < (ft_lstsize(*b_stack) / 2))
		{
			while (depth > 0)
			{
				ft_ra_rb(b_stack, 'b');
				depth--;
			}
		}
		else
		{
			rdepth = ft_lstsize(*b_stack) - depth;
			while (rdepth > 0)
			{
				ft_rra_rrb(b_stack, 'b');
				rdepth--;
			}
		}
		ft_pa_pb(b_stack, a_stack, 'a');
		ft_del_last(b_sort);
		b_stack_size--;
	}
	ft_pa_pb(b_stack, a_stack, 'a');
	ft_lstclear(b_sort);
}

int	push_swap(t_list **a_stack, t_list **b_stack)
{
	t_list *b_sort;

	// ft_printf("quicksort_a2b\n");
	quicksort_a2b(a_stack, b_stack);
	// print_list(*a_stack, "a");
	// print_list(*b_stack, "b");
	b_sort = ft_sort_stack(*b_stack);
	// ft_printf("quicksort_b2a\n");
	quicksort_b2a(a_stack, b_stack, &b_sort);
	// print_list(*a_stack, "a");
	// print_list(*b_stack, "b");
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (argc <= 2)
		return (ft_error());
	if (ft_checkinputs(argc, argv) == 1)
		return (1);
	a_stack = ft_makelist(argc, argv);
	if (!a_stack)
		return (ft_error());
	b_stack = NULL;
	// print_tests(a_stack, b_stack);
	if (ft_check_list(a_stack) == 0)
		return (0);
	if (argc <= 4)
		return (ft_simple_sort(a_stack), 0);
	else
	push_swap(&a_stack, &b_stack);
	free(a_stack);
	return (0);
}
