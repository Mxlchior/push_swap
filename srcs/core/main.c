/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:59:52 by megrelli          #+#    #+#             */
/*   Updated: 2026/05/01 06:37:37 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	handle_args_error(char **args, int is_split)
{
	if (!args)
		return (1);
	if (!args[0])
	{
		if (is_split)
			free(args);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

static void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	if (!is_sorted(a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			turk_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				is_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	args = parse_args(argc, argv, &is_split);
	if (handle_args_error(args, is_split) == 1)
		return (1);
	if (init_stack_a(&a, args) == 1)
	{
		if (is_split)
			ft_free_tab(args);
		return (1);
	}
	sort_stacks(&a, &b);
	if (is_split)
		ft_free_tab(args);
	ft_free_stack(&a);
}
