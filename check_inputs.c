/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:14:33 by kcouchma          #+#    #+#             */
/*   Updated: 2023/12/04 15:26:24 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (j == 0)
			return (1);
		i++;
	}
	return (0);
}

long	ftps_atoi(char *argv)
{
	long	num;
	int		i;
	int		is_neg;

	num = 0;
	i = 0;
	is_neg = 1;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			is_neg = -1;
		i++;
	}
	while (argv[i])
	{
		num *= 10;
		num += argv[i] - '0';
		i++;
	}
	if (is_neg == -1)
		num = -num;
	if (num <= 2147483647 && num >= -2147483648)
		return (num);
	return (-2147483649);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkinputs(int argc, char **argv)
{
	int		i;
	int		num_nums;

	num_nums = 0;
	if (is_not_num(argc, argv) == 1)
		return (ft_error());
	i = 1;
	while (i < argc)
	{
		if (ftps_atoi(argv[i]) == -2147483649)
			return (ft_error());
		i++;
	}
	if (is_dup(argc, argv) == 1)
		return (ft_error());
	return (0);
}
