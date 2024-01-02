/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:41:02 by kcouchma          #+#    #+#             */
/*   Updated: 2024/01/02 14:55:40 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_turny(t_list **stack, char a_b, int depth, int size)
{
	int	offset;

	if (a_b == 'a')
		offset = -1;
	else
		offset = 0;
	if (depth <= size / 2)
	{
		while (depth > 0)
		{
			ft_ra_rb(stack, a_b);
			depth--;
		}
	}
	else
	{
		depth = (size - (depth - 1)) + offset;
		while (depth > 0)
		{
			ft_rra_rrb(stack, a_b);
			depth--;
		}
	}
}

void	ft_big2a(t_list **a_stack, t_list **b_stack)
{
	int		b_size;
	int		depth;
	int		i;
	t_list	*temp;

	temp = *b_stack;
	b_size = ft_lstsize(*b_stack) - 1;
	depth = 0;
	i = 0;
	while (temp)
	{
		if (temp->index == b_size)
		{
			depth = i;
			break ;
		}
		temp = temp->next;
		i++;
	}
	ft_turny(b_stack, 'b', depth, b_size);
	ft_pa_pb(b_stack, a_stack, 'a');
}

int	ft_closest(t_list *a_stack, int index)
{
	int	closest;
	int	pos_closest;
	int	i;

	closest = 10000;
	pos_closest = 0;
	i = 0;
	while (a_stack)
	{
		if (a_stack->index > index && ((a_stack->index - index) <= closest))
		{
			closest = a_stack->index - index;
			pos_closest = i;
		}
		a_stack = a_stack->next;
		i++;
	}
	return (pos_closest);
}
