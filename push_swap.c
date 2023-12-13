/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/13 13:04:48 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_sort(t_list **a_stack)
{
	int	i;

	i = 0;
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
// A2B Split Quicksort /////////////////////////////////////////////////////
// Find first value of chunk in the list, calculate the depth, rotate in the
// right direction.

// find first and last member of chunk - which is closer?
int	ft_find_chunk(t_list **b_stack, int chunk)
{
	t_list	*temp;
	int		fdepth;
	int		ldepth;
	int		i;

	temp = *b_stack;
	fdepth = -1;
	ldepth = 0;
	i = 0;
	while (temp)
	{
		if (temp->index <= chunk && (temp->index >= (chunk - chunk)))
		{
			if (fdepth == -1)
				fdepth = i;
			ldepth = i;
		}
		temp = temp->next;
		i++;
	}
	if (fdepth <= 0)
		return (0);
	if (fdepth <= (i - ldepth))
		return (fdepth);
	return (ldepth);
}

// rotate until until we're on the border of the right chunk
void	ft_turny(t_list **a_stack, t_list **b_stack, int depth, int b_size)
{
	if (depth <= b_size / 2)
	{
		while (depth > 0)
		{
			ft_ra_rb(b_stack, 'b');
			depth--;
		}
	}
	else
	{
		depth = b_size - depth;
		while (depth > 0)
		{
			ft_rra_rrb(b_stack, 'b');
			depth--;
		}
	}
	ft_pa_pb(a_stack, b_stack, 'b');
}
// A2B Split Quicksort /////////////////////////////////////////////////////
// Leave three behind
void	quicksort_a2b(t_list **a_stack, t_list **b_stack, int argc)
{
	int	chunk;
	int	it_chunk;
	int	depth;
	int	b_size;
	int	a_size;

	a_size = ft_lstsize(*a_stack);
	argc = argc - 3;
	if (argc < 20)
		chunk = argc;
	else
		chunk = argc * 0.10;
	it_chunk = chunk;
	depth = 0;
	while (a_size >= 3)
	{
		while (a_size >= 3)
		{//THIS BIT IS NOT WORKING////////////////////////////////
			if (((*a_stack)->index <= chunk) && ((*a_stack)->index < argc))
			{
				depth = ft_find_chunk(b_stack, chunk);
				b_size = ft_lstsize(*b_stack);
				ft_turny(a_stack, b_stack, depth, b_size);
			}
			// else if (((*a_stack)->index <= (chunk + it_chunk)) && (*a_stack)->index < argc)
			// {
			// 	depth = ft_find_chunk(b_stack, chunk + it_chunk);
			// 	b_size = ft_lstsize(*b_stack);
			// 	ft_turny(a_stack, b_stack, depth, b_size);
			// }
			else
				ft_ra_rb(a_stack, 'a');
			a_size--;
		}
		chunk += it_chunk + it_chunk;
		a_size = ft_lstsize(*a_stack);
	}
	// if (ft_check_list(*a_stack) == 1)
	// 	ft_simple_sort(a_stack);
	print_list(*a_stack, "a");
	return ;
}

// A2B Split Quicksort /////////////////////////////////////////////////////
// Empty a_stack totally - works but kills the smaller stack case (5 numbers)
// void	quicksort_a2b(t_list **a_stack, t_list **b_stack)
// {
// 	int	a_size;
// 	int	chunk;
// 	int	it_chunk;
// 	int	depth;
// 	int	b_size;

// 	a_size = ft_lstsize(*a_stack);
// 	if (a_size < 20)
// 		chunk = a_size;
// 	else
// 		chunk = a_size * 0.10;
// 	it_chunk = chunk;
// 	depth = 0;
// 	while (a_size > 0)
// 	{
// 		while (a_size > 0)
// 		{
// 			if ((*a_stack)->index <= chunk)
// 			{
// 				depth = ft_find_chunk(b_stack, chunk);
// 				b_size = ft_lstsize(*b_stack);
// 				ft_turny(a_stack, b_stack, depth, b_size);
// 			}
// 			else if ((*a_stack)->index <= (chunk + it_chunk))
// 			{
// 				depth = ft_find_chunk(b_stack, chunk + it_chunk);
// 				b_size = ft_lstsize(*b_stack);
// 				ft_turny(a_stack, b_stack, depth, b_size);
// 			}
// 			else
// 				ft_ra_rb(a_stack, 'a');
// 			a_size--;
// 		}
// 		chunk += it_chunk + it_chunk;
// 		a_size = ft_lstsize(*a_stack);
// 	}
// }

// B2A ROTATE A /////////////////////////////////////////////////////////////
//THIS CLOSEST DEFAULT WILL BREAK EVENTUALLY IF THERE ARE TOO MANY NUMBERS
// int	ft_closest(t_list *a_stack, int index)
// {
// 	int	closest;
// 	int	pos_closest;
// 	int	i;

// 	closest = 10000;
// 	pos_closest = 0;
// 	i = 0;
// 	while (a_stack)
// 	{
// 		if (a_stack->index > index && ((a_stack->index - index) <= closest))
// 		{
// 			closest = a_stack->index - index;
// 			pos_closest = i;
// 		}
// 		a_stack = a_stack->next;
// 		i++;
// 	}
// 	return (pos_closest);
// }

// void	quicksort_b2a(t_list **a_stack, t_list **b_stack, int argc)
// {
// 	// int		b_stack_size;
// 	int		a_stack_size;
// 	int		closest;
// 	// t_list	*a_last;

// 	// argc = ft_lstsize(*b_stack);

// 	closest = ft_closest(*b_stack, argc - 1);
// 	ft_printf("FIRSTclosest %d\n", closest);
// 	if (closest <= (argc / 2))
// 	{
// 		while (closest > 0)
// 		{
// 			ft_ra_rb(b_stack, 'b');
// 			closest--;
// 		}
// 	}
// 	else
// 	{
// 		closest = argc - closest;
// 		while (closest > 0)
// 		{
// 			ft_rra_rrb(b_stack, 'b');
// 			closest--;
// 		}
// 	}
// 	ft_pa_pb(b_stack, a_stack, 'a');
// 	argc--;
// 	while (argc >= 0)
// 	{
// 		closest = ft_closest(*a_stack, (*b_stack)->index);
// 		a_stack_size = ft_lstsize(*a_stack);
// 		if (closest <= (a_stack_size / 2))
// 		{
// 			while (closest > 0)
// 			{
// 				ft_ra_rb(a_stack, 'a');
// 				closest--;
// 			}
// 		}
// 		else
// 		{
// 			closest = argc - closest;
// 			while (closest > 0)
// 			{
// 				ft_rra_rrb(a_stack, 'a');
// 				closest--;
// 			}
// 		}
// 		ft_pa_pb(b_stack, a_stack, 'a');
// 		argc--;
// 	}
// 	closest = ft_closest(*a_stack, -1);
// 	a_stack_size = ft_lstsize(*a_stack);
// 	if (closest <= (a_stack_size / 2))
// 	{
// 		while (closest > 0)
// 		{
// 			ft_ra_rb(a_stack, 'a');
// 			closest--;
// 		}
// 	}
// 	else
// 	{
// 		closest = a_stack_size - closest;
// 		while (closest > 0)
// 		{
// 			ft_rra_rrb(a_stack, 'a');
// 			closest--;
// 		}
// 	}
// }

// B2A ROTATE B /////////////////////////////////////////////////////////////
// B2A ROTATE B - USES ARGC /////////////////////////////////////////////////

int	ft_depth(t_list *stack, int index)
{
	int	depth;

	depth = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		depth++;
	}
	return (depth);
}

void	quicksort_b2a(t_list **a_stack, t_list **b_stack, int argc)
{
	int	b_stack_size;
	int	depth;

	b_stack_size = ft_lstsize(*b_stack);
	while (b_stack_size > 0)
	{
		depth = ft_depth(*b_stack, argc);
		if (depth <= (b_stack_size / 2))
		{
			while (depth > 0)
			{
				ft_ra_rb(b_stack, 'b');
				depth--;
			}
		}
		else
		{
			depth = b_stack_size - depth;
			while (depth > 0)
			{
				ft_rra_rrb(b_stack, 'b');
				depth--;
			}
		}
		ft_pa_pb(b_stack, a_stack, 'a');
		argc--;
		b_stack_size--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (argc < 2)
		return (0);
	if (ft_checkinputs(argc, argv) == 1)
		return (1);
	if (argc == 2)
		return (0);
	a_stack = ft_makelist(argc, argv);
	if (!a_stack)
		return (1);
	b_stack = NULL;
	if (ft_check_list(a_stack) == 0)
		return (0);
	if (argc <= 4)
		return (ft_simple_sort(&a_stack), 0);
	quicksort_a2b(&a_stack, &b_stack, argc - 2);
	// quicksort_b2a(&a_stack, &b_stack, argc - 2);
	ft_lstclear(&a_stack);
	return (0);
}
