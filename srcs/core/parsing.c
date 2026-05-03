/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:59:22 by megrelli          #+#    #+#             */
/*   Updated: 2026/05/03 05:32:28 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	is_syntax_valid(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

char	**parse_args(int argc, char **argv, int *is_split)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 9 && argv[1][i] <= 13)
				argv[1][i] = 32;
			i++;
		}
		args = ft_split(argv[1], ' ');
		*is_split = 1;
	}
	else
	{
		args = argv + 1;
		*is_split = 0;
	}
	return (args);
}

int	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		if (!is_syntax_valid(argv[i]))
			return (ft_error(a));
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (ft_error(a));
		if (is_duplicate(*a, nbr))
			return (ft_error(a));
		if (append_node(a, nbr) == 1)
			return (ft_error(a));
		i++;
	}
	return (0);
}
