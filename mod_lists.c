/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:14:56 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/01 11:53:22 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	new_list = NULL;
	temp = lst;
	while (temp)
	{
		new_node = ft_lstnew(0);
		if (!new_node)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		new_node->num = f(temp->num);
		ft_lstadd_back(&new_list, new_node);
		temp = temp->next;
	}
	return (new_list);
}

void	ft_lstiter(t_list *lst, int(*f)(int))
{
	while (lst)
	{
		f(lst->num);
		lst = lst->next;
	}
}

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