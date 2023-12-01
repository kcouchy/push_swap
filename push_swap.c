/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/01 13:54:32 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_makelist(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*temp;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			a_stack = ft_lstnew(ft_atoi(argv[i]));
			if (!a_stack)
				return (a_stack);
		}
		else
		{
			temp = ft_lstnew(ft_atoi(argv[i]));
			if (!temp)
				return (temp);
			ft_lstadd_back(&a_stack, temp);
		}
		i++;
	}
	return (a_stack);
}
void print_list(t_list *a_stack)
{
	while (a_stack)
	{
		printf("%d ", a_stack->num);
		a_stack = a_stack->next;
	}
}

void	push_swap(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (ft_checkinputs(argc, argv) == 1)
		return ;
	a_stack = ft_makelist(argc, argv);
	if (!a_stack)
	{
		ft_error();
		return ;
	}
	b_stack = NULL;
	
	print_list(a_stack);
	ft_lstclear(&b_stack);
	return ;
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
//	printf("%d", push_swap(argc, argv));
	return (0);
}