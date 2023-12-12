
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_combi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:43:02 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/04 16:25:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_list *a_list, t_list *b_list)
{
	int		i;

	i = a_list->num;
	if (ft_lstsize(a_list) <= 1 || ft_lstsize(b_list) <= 1)
		return (1);
	else
	{
		a_list->num = a_list->next->num;
		a_list->next->num = i;
		i = b_list->num;
		b_list->num = b_list->next->num;
		b_list->next->num = i;
	}
	ft_printf("ss\n");
	return (0);
}

int	ft_rr(t_list **a_list, t_list **b_list)
{
	t_list	*temp;

	temp = (*a_list)->next;
	if (ft_lstsize(*a_list) <= 1 || ft_lstsize(*b_list) <= 1)
		return (1);
	else
	{
		ft_lstadd_back(&temp, *a_list);
		(*a_list)->next = NULL;
		*a_list = temp;
		temp = (*b_list)->next;
		ft_lstadd_back(&temp, *b_list);
		(*b_list)->next = NULL;
		*b_list = temp;
	}
	ft_printf("rr\n");
	return (0);
}

int	ft_rrr(t_list **a_list, t_list **b_list)
{
	t_list	*temp;
	t_list	**end;

	temp = *a_list;
	end = a_list;
	if (ft_lstsize(*a_list) <= 1 || ft_lstsize(*b_list) <= 1)
		return (1);
	while (temp->next)
		temp = temp->next;
	while ((*end)->next->next)
		end = &(*end)->next;
	ft_lstadd_front(a_list, temp);
	(*end)->next = NULL;
	temp = *b_list;
	end = b_list;
	while (temp->next)
		temp = temp->next;
	while ((*end)->next->next)
		end = &(*end)->next;
	ft_lstadd_front(b_list, temp);
	(*end)->next = NULL;
	ft_printf("rrr\n");
	return (0);
}
