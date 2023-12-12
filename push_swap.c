/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/12 17:55:41 by kcouchma         ###   ########.fr       */
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
	if ((ft_lstsize(*a_stack) == 3) && 
		((*a_stack)->next->num > (*a_stack)->next->next->num))
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

void	quicksort_a2b(t_list **a_stack, t_list **b_stack)
{
	int	a_size;
	int	chunk;
	int	it_chunk;
	int	depth;
	int	b_size;

	a_size = ft_lstsize(*a_stack);
	if (a_size < 20)
		chunk = a_size;
	else
		chunk = a_size * 0.15;
	it_chunk = chunk;
	depth = 0;
	while (a_size > 1)
	{
		while (a_size > 0)
		{
			if ((*a_stack)->index <= chunk)
			{
				depth = ft_find_chunk(b_stack, chunk);
				b_size = ft_lstsize(*b_stack);
				// ft_printf("first: %d", chunk);
				ft_turny(a_stack, b_stack, depth, b_size);
			}
			else if ((*a_stack)->index <= (chunk + it_chunk))
			{
				depth = ft_find_chunk(b_stack, chunk + it_chunk);
				b_size = ft_lstsize(*b_stack);
				// ft_printf("second: %d", chunk + it_chunk);
				ft_turny(a_stack, b_stack, depth, b_size);
			}
			else
				ft_ra_rb(a_stack, 'a');
			a_size--;
		}
		chunk += it_chunk + it_chunk;
		// ft_printf("nextloop: %d", chunk);
		a_size = ft_lstsize(*a_stack);
	}
}

// A2B Median Quicksort /////////////////////////////////////////////////////
// void	quicksort_back(t_list **a_stack, t_list **b_stack, int len)
// {
// 	int	pivot;

// 	pivot = ft_findpivot(*b_stack);
// 	while (len > 0)
// 	{
// 		if ((*b_stack)->num > pivot)
// 			ft_pa_pb(b_stack, a_stack, 'a');
// 		else
// 			ft_ra_rb(b_stack, 'b');
// 		len--;
// 	}
// 	return ;
// }

// void	quicksort_fwd(t_list **a_stack, t_list **b_stack, int len)
// {
// 	int	pivot;
// 	int	i;
	
// 	pivot = ft_findpivot(*a_stack);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if ((*a_stack)->num < pivot)
// 			ft_pa_pb(a_stack, b_stack, 'b');
// 		else
// 			ft_ra_rb(a_stack, 'a');
// 		i++;
// 	}
// 	if (len > 220)
// 	{
// 		quicksort_back(a_stack, b_stack, len / 2);
// 		quicksort_fwd(a_stack, b_stack, len / 2);
// 	}
// 	return ;
// }

// void	quicksort_a2b(t_list **a_stack, t_list **b_stack)
// {
// 	int	a_list_len;

// 	a_list_len = ft_lstsize(*a_stack);
// 	while(a_list_len > 3)
// 	{
// 		quicksort_fwd(a_stack, b_stack, a_list_len);
// 		a_list_len = ft_lstsize(*a_stack);
// 	}
// 	if (ft_check_list(*a_stack) != 0)
// 		ft_simple_sort(a_stack);
// 	return ;
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

// void	quicksort_b2a(t_list **a_stack, t_list **b_stack)
// {
// 	int		b_stack_size;
// 	int		a_stack_size;
// 	int		closest;
// 	t_list	*a_last;

// 	b_stack_size = ft_lstsize(*b_stack);
// 	while (b_stack_size > 0)
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
// 		else if (closest > (a_stack_size / 2))
// 		{
// 			while (closest < a_stack_size)
// 			{
// 				ft_rra_rrb(a_stack, 'a');
// 				closest++;
// 			}
// 		}
// 		ft_pa_pb(b_stack, a_stack, 'a');
// 		b_stack_size--;
// 	}
// 	a_last = ft_lstlast(*a_stack);
// 	while (a_last->num < (*a_stack)->num)
// 	{
// 		ft_rra_rrb(a_stack, 'a');
// 		a_last = ft_lstlast(*a_stack);
// 	}
// }


// FURTHER OPTI
// void	quicksort_b2a(t_list **a_stack, t_list **b_stack)
// {
// 	int		b_stack_size;
// 	int		a_stack_size;

// 	if (a_stack_size < b_stack_size)
// 		rotate a_stack
// 	else if (b_stack_size < a_stack_size)
// 		rotate b stack (old quicksort b2a below)
// }


// B2A ROTATE B /////////////////////////////////////////////////////////////
int		ft_depth(t_list *stack, int num)
{
	int	depth;

	depth = 0;
	while (stack)
	{
		if (stack->num == num)
			break ;
		stack = stack->next;
		depth++;
	}
	return (depth);
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
	ft_lstclear(b_sort);
}

// MAIN /////////////////////////////////////////////////////////////////////
int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*b_sort;

	if (argc < 2)
		return (0);
	if (ft_checkinputs(argc, argv) == 1)
		return (1);
	if (argc == 2)
		return (0);
	a_stack = ft_makelist(argc, argv);
	// print_list(a_stack, "a");
	if (!a_stack)
		return (1);
	b_stack = NULL;
	// print_tests(a_stack, b_stack);
	if (ft_check_list(a_stack) == 0)
		return (0);
	if (argc <= 4)
		return (ft_simple_sort(&a_stack), 0);
	quicksort_a2b(&a_stack, &b_stack);
	// print_list(a_stack, "a");
	// print_list(b_stack, "b");
	// quicksort_b2a(&a_stack, &b_stack);
	// print_list(a_stack, "a");
	// print_list(b_stack, "b");
	b_sort = ft_sort_stack(b_stack);
	quicksort_b2a(&a_stack, &b_stack, &b_sort);
	ft_lstclear(&a_stack);
	return (0);
}
