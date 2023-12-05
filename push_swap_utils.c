/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:39 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/05 16:38:29 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack)
{
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

int	ft_findpivot(t_list *a_stack)
{
	t_list	*pivot;
	t_list	*temp;
	int		list_len;

	temp = ft_lstmap(a_stack);
	list_len = ft_lstsize(a_stack) / 2;
	while (ft_check_list(temp) == 1)
	{
		pivot = temp;
		while(pivot->next)
		{
			if (pivot->num > pivot->next->num)
				swap_nums(pivot, pivot->next);
			pivot = pivot->next;
		}
	}
	pivot = temp;
	while (list_len > 0)
	{
		pivot = pivot->next;
		list_len--;
	}
	free(temp);
	list_len = pivot->num;
	return (list_len);
}
