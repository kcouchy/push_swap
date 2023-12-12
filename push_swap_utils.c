/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:39 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/12 15:11:57 by kcouchma         ###   ########.fr       */
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
	int	n;
	int	pivot_index;
	int	pivot;
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

// OLD FIND_PIVOT - creates and checks against a sortlist
// FOR NEW VERSIONS : TEST WITH INPUT BELOW, PIVOT SHOULD BE 5 then 8
// ./push_swap 6 5 8 -10 0 654654 -464552 -56513 1236
// int	ft_findpivot(t_list *a_stack)
// {
// 	t_list	*sorted;
// 	int		list_len;
// 	int		pivot;

// 	sorted = ft_sort_stack(a_stack);
// 	print_list(a_stack, "a");
// 	list_len = ft_lstsize(sorted) / 2;
// 	while (list_len > 0)
// 	{
// 		sorted = sorted->next;
// 		list_len--;
// 	}
// 	pivot = sorted->num;
// 	free(sorted);
// 	ft_printf("pivot: %d", pivot);
// 	return (pivot);
// }