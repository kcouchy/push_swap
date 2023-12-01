/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:55:02 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/01 17:09:40 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*ft_swap2(t_list *list, char a_b)
{
	int		i;
	
	i = list->num;
	list->num = list->next->num;
	list->next->num = i;

	write(1, "s", );
	write(1, &a_b, 1);
	write(1, "\n", 1);
	//change this to use my ft_printf("s%c\n", a_b);
	return (a_list)
}

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of 
// a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of 
// b.
// Do nothing if a is empty.


// t_list	*ft_sa(t_list *a_list, t_list *b_list)
// {
// 	t_list	*temp;
// 	int		i;

// 	i = 0;
// 	temp = a_list;
// 	if (ft_lstsize(a_list) < 2)
// 	{
// 		write(1, "sa\n", 3);
// 		return (a_list);
// 	}
// 	if (ft_lstsize(b_list) == 0)
// 	{
// 		b_list = ft_lstnew(a_list->num);
// 		if(!b_list)
// 			return (error());
// 		a_list = a_list->next;
// 		i++;
// 	}
// 	while (i < 2)
// 	{
// 		temp = ft_lstnew(a_list->num);
// 		if(!temp)
// 			return (error());
// 		b_list = ft_lstadd_front(&b_list, temp)
// 		a_list = a_list->next;
// 		ft_ra(b_list);
// 		i++;
// 	}
// 	free(temp);
// 	write(1, "sa\n", 3)
// 	return (a_list);
// }