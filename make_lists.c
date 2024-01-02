/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:02:24 by kcouchma          #+#    #+#             */
/*   Updated: 2024/01/02 15:48:34 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*add2list;

	add2list = malloc(sizeof(t_list));
	if (add2list)
	{
		add2list->num = num;
		add2list->next = NULL;
	}
	return (add2list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
}

t_list	*ft_lstmap(t_list *lst)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	new_list = NULL;
	temp = lst;
	while (temp)
	{
		new_node = ft_lstnew(temp->num);
		if (!new_node)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		temp = temp->next;
	}
	return (new_list);
}

t_list	*ft_makelist(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*temp;
	int		i;

	i = 1;
	a_stack = NULL;
	while (i < argc)
	{
		temp = ft_lstnew(ftps_atoi(argv[i]));
		if (!temp)
			return (temp);
		ft_lstadd_back(&a_stack, temp);
		i++;
	}
	ft_addindex(&a_stack);
	return (a_stack);
}
