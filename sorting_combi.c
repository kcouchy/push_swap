/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_combi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:43:02 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/13 10:49:49 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_ss(t_list *a_list, t_list *b_list)
// {
// 	int		i;
// 	int		j;

// 	i = a_list->num;
// 	j = a_list->index;
// 	if (ft_lstsize(a_list) <= 1 || ft_lstsize(b_list) <= 1)
// 		return (1);
// 	else
// 	{
// 		a_list->num = a_list->next->num;
// 		a_list->next->num = i;
// 		a_list->index = a_list->next->index;
// 		a_list->next->index = j;
// 		i = b_list->num;
// 		j = b_list->index;
// 		b_list->num = b_list->next->num;
// 		b_list->next->num = i;
// 		b_list->index = b_list->next->index;
// 		b_list->next->index = j;
// 	}
// 	ft_printf("ss\n");
// 	return (0);
// }

// int	ft_rr(t_list **a_list, t_list **b_list)
// {
// 	t_list	*temp;

// 	temp = (*a_list)->next;
// 	if (ft_lstsize(*a_list) <= 1 || ft_lstsize(*b_list) <= 1)
// 		return (1);
// 	else
// 	{
// 		ft_lstadd_back(&temp, *a_list);
// 		(*a_list)->next = NULL;
// 		*a_list = temp;
// 		temp = (*b_list)->next;
// 		ft_lstadd_back(&temp, *b_list);
// 		(*b_list)->next = NULL;
// 		*b_list = temp;
// 	}
// 	ft_printf("rr\n");
// 	return (0);
// }

// int	ft_rrr(t_list **a_list, t_list **b_list)
// {
// 	t_list	*temp;
// 	t_list	**end;

// 	temp = *a_list;
// 	end = a_list;
// 	if (ft_lstsize(*a_list) <= 1 || ft_lstsize(*b_list) <= 1)
// 		return (1);
// 	while (temp->next)
// 		temp = temp->next;
// 	while ((*end)->next->next)
// 		end = &(*end)->next;
// 	ft_lstadd_front(a_list, temp);
// 	(*end)->next = NULL;
// 	temp = *b_list;
// 	end = b_list;
// 	while (temp->next)
// 		temp = temp->next;
// 	while ((*end)->next->next)
// 		end = &(*end)->next;
// 	ft_lstadd_front(b_list, temp);
// 	(*end)->next = NULL;
// 	ft_printf("rrr\n");
// 	return (0);
// }
