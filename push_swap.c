/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/04 17:14:21 by kcouchma         ###   ########.fr       */
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
			a_stack = ft_lstnew(ftps_atoi(argv[i]));
			if (!a_stack)
				return (a_stack);
		}
		else
		{
			temp = ft_lstnew(ftps_atoi(argv[i]));
			if (!temp)
				return (temp);
			ft_lstadd_back(&a_stack, temp);
		}
		i++;
	}
	return (a_stack);
}

void	print_list(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->num);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_tests(t_list *a_stack, t_list *b_stack)
{
	ft_printf("\n///test ft_sa_sb:///\n");
	print_list(a_stack);
	ft_sa_sb(a_stack, 'a');
	print_list(a_stack);

	ft_printf("\n///test ft_pa_pb:///\n");
	print_list(a_stack);
	print_list(b_stack);
	ft_pa_pb(&a_stack, &b_stack, 'b');
	print_list(a_stack);
	print_list(b_stack);
	ft_pa_pb(&b_stack, &a_stack, 'a');
	print_list(a_stack);
	print_list(b_stack);

	ft_printf("\n///test ft_ra_rb:///\n");
	print_list(a_stack);
	ft_ra_rb(&a_stack, 'a');
	print_list(a_stack);

	ft_printf("\n///test ft_rra_rrb:///\n");
	print_list(a_stack);
	ft_rra_rrb(&a_stack, 'a');
	print_list(a_stack);
	ft_pa_pb(&a_stack, &b_stack, 'b');
	ft_pa_pb(&a_stack, &b_stack, 'b');
	ft_pa_pb(&a_stack, &b_stack, 'b');

	ft_printf("\n///test ft_ss:///\n");
	print_list(a_stack);
	print_list(b_stack);
	ft_ss(a_stack, b_stack);
	print_list(a_stack);
	print_list(b_stack);

	ft_printf("\n///test ft_rr:///\n");
	print_list(a_stack);
	print_list(b_stack);
	ft_rr(&a_stack, &b_stack);
	print_list(a_stack);
	print_list(b_stack);

	ft_printf("\n///test ft_rrr:///\n");
	print_list(a_stack);
	print_list(b_stack);
	ft_rrr(&a_stack, &b_stack);
	print_list(a_stack);
	print_list(b_stack);
	
	ft_lstclear(&a_stack);
	ft_lstclear(&b_stack);
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
	print_tests(a_stack, b_stack);
	return ;
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
