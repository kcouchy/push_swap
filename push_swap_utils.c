/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:39 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/13 11:04:49 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack, char *name)
{
	ft_printf("%s :\n", name);
	while (stack)
	{
		ft_printf("in: %d num:%d \n", stack->index, stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	swap_nums(t_list *stack1, t_list *stack2)
{
	int		temp;
	int		temp2;

	temp = stack1->num;
	temp2 = stack1->index;
	stack1->num = stack2->num;
	stack2->num = temp;
	stack1->index = stack2->index;
	stack2->index = temp2;
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

t_list	*ft_sort_stack(t_list *stack)
{
	t_list	*sorted;
	t_list	*temp;

	sorted = ft_lstmap(stack);
	if (!sorted)
		return (NULL);
	while (ft_check_list(sorted) == 1)
	{
		temp = sorted;
		while (temp->next)
		{
			if (temp->num > temp->next->num)
				swap_nums(temp, temp->next);
			temp = temp->next;
		}
	}
	return (sorted);
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
