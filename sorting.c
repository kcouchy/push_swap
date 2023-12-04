/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:55:02 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/04 16:07:18 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa_sb(t_list *list, char a_b)
{
	int		i;

	i = list->num;
	if (ft_lstsize(list) <= 1)
		return (1);
	list->num = list->next->num;
	list->next->num = i;
	ft_printf("s%c\n", a_b);
	return (0);
}

int	ft_pa_pb(t_list **source_list, t_list **target_list, char a_b)
{
	t_list	*temp;

	temp = (*source_list)->next;
	if (ft_lstsize(*source_list) == 0)
		return (1);
	else
	{
		ft_lstadd_front(target_list, *source_list);
		*source_list = temp;
	}
	ft_printf("p%c\n", a_b);
	return (0);
}

int	ft_ra_rb(t_list **list, char a_b)
{
	t_list	*temp;

	temp = (*list)->next;
	if (ft_lstsize(*list) <= 1)
		return (1);
	else
	{
		ft_lstadd_back(&temp, *list);
		(*list)->next = NULL;
		*list = temp;
	}
	ft_printf("r%c\n", a_b);
	return (0);
}

int	ft_rra_rrb(t_list **list, char a_b)
{
	t_list	*temp;
	t_list	**end;

	temp = *list;
	end = list;
	if (ft_lstsize(*list) <= 1)
		return (1);
	else
	{
		while (temp->next)
			temp = temp->next;
		while ((*end)->next->next)
			end = &(*end)->next;
		ft_lstadd_front(list, temp);
		(*end)->next = NULL;
	}
	ft_printf("rr%c\n", a_b);
	return (0);
}
