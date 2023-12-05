/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/05 18:57:42 by kcouchma         ###   ########.fr       */
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

t_list	*ft_makelist(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*temp;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			a_stack = ft_lstnew(ftps_atoi(argv[i]));
			if (!a_stack)
				return (a_stack);
		}
		else
		{
			temp = ft_lstnew(ftps_atoi(argv[i]));
			if (!temp)
				return (temp);
			ft_lstadd_back(&a_stack, temp);
		}
		i++;
	}
	return (a_stack);
}

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

void	quick_sort_a(t_list **a_stack, t_list **b_stack, int pivot, int len)
{
	if (len > 3)
	{
		if ((*a_stack)->num < pivot)
			ft_pa_pb(a_stack, b_stack, 'b');
		else
			ft_ra_rb(a_stack, 'a');
		quick_sort_a(a_stack, b_stack, ft_findpivot(*a_stack), ft_lstsize(*a_stack));
	}
	return (ft_simple_sort(*a_stack));
	
}
void	ft_sort(t_list *a_stack, t_list *b_stack)
{
	int	pivot;
	int	a_list_len;

	pivot = 0;
	a_list_len = ft_lstsize(a_stack);
	while (ft_lstsize(a_stack) > 3)
	{
		pivot = ft_findpivot(a_stack);
		quick_sort_a(&a_stack, &b_stack, pivot, a_list_len);
		print_list(a_stack);
		print_list(b_stack);
	}
}

int	push_swap(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (ft_checkinputs(argc, argv) == 1)
		return (1);
	a_stack = ft_makelist(argc, argv);
	if (!a_stack)
		return ft_error();
	b_stack = NULL;
	//print_tests(a_stack, b_stack);
	if (ft_check_list(a_stack) == 0)
		return (0);
	if (argc <= 4)
		return (ft_simple_sort(a_stack), 0);
	else
	ft_sort(a_stack, b_stack);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
