/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:39 by kcouchma          #+#    #+#             */
/*   Updated: 2024/01/02 15:48:28 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	ft_check_list(t_list *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_findpivot(t_list *a_stack)
{
	int		n;
	int		pivot_index;
	int		pivot;
	t_list	*temp;

	pivot_index = 0;
	n = 0;
	pivot = a_stack->num;
	temp = a_stack;
	while (temp)
	{
		pivot_index += temp->index;
		n++;
		temp = temp->next;
	}
	pivot_index /= n;
	while (a_stack)
	{
		if (a_stack->index == pivot_index)
			pivot = a_stack->num;
		a_stack = a_stack->next;
	}
	return (pivot);
}
