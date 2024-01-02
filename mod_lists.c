/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:14:56 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/15 16:30:30 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_len;

	lst_len = 0;
	while (lst)
	{
		lst_len++;
		lst = lst->next;
	}
	return (lst_len);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
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

int	ft_addindex(t_list **a_stack)
{
	t_list	*sorted;
	t_list	*temp;
	t_list	*temp2;
	int		i;

	i = 0;
	sorted = ft_sort_stack(*a_stack);
	if (!sorted)
		return (1);
	temp2 = sorted;
	while (sorted)
	{
		sorted->index = i;
		temp = *a_stack;
		while (temp)
		{
			if (temp->num == sorted->num)
				temp->index = sorted->index;
			temp = temp->next;
		}
		sorted = sorted->next;
		i++;
	}
	ft_lstclear(&temp2);
	return (0);
}
