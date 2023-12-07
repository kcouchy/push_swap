/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:39 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/06 17:14:12 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack, char *name)
{
	ft_printf("%s : ", name);
	while (stack)
	{
		ft_printf("%d ", stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	swap_nums(t_list *stack1, t_list *stack2)
{
	int		temp;

	temp = stack1->num;
	stack1->num = stack2->num;
	stack2->num = temp;
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
	if(!sorted)
		return (NULL);
	while (ft_check_list(sorted) == 1)
	{
		temp = sorted;
		while(temp->next)
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
	t_list	*sorted;
	int		list_len;
	int		pivot;

	sorted = ft_sort_stack(a_stack);
	list_len = ft_lstsize(sorted) / 2;
	while (list_len > 0)
	{
		sorted = sorted->next;
		list_len--;
	}
	pivot = sorted->num;
	free(sorted);
	return (pivot);
}