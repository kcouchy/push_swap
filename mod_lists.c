/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:14:56 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/13 12:16:56 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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

// void	ft_del_last(t_list **lst_ptr)
// {
// 	if (*lst_ptr == NULL)
// 		return ;
// 	while ((*lst_ptr)->next)
// 		lst_ptr = &(*lst_ptr)->next;
// 	free(*lst_ptr);
// 	*lst_ptr = NULL;
// }

int	ft_addindex(t_list **a_stack)
{
	t_list	*sorted;
	t_list	*temp;
	int		i;

	i = 0;
	sorted = ft_sort_stack(*a_stack);
	if (!sorted)
		return (ft_error());
	temp = *a_stack;
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
	ft_lstclear(&sorted);
	return (0);
}
