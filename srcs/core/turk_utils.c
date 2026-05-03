/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:43:50 by megrelli          #+#    #+#             */
/*   Updated: 2026/04/30 02:49:03 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

t_stack_node	*get_target_in_b(t_stack_node *node, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*current;

	target = NULL;
	current = b;
	while (current)
	{
		if (node->value > current->value)
		{
			if (!target)
				target = current;
			else if (target->value < current->value)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = get_highest(b);
	return (target);
}

t_stack_node	*get_target_in_a(t_stack_node *node, t_stack_node *a)
{
	t_stack_node	*target;
	t_stack_node	*current;

	target = NULL;
	current = a;
	while (current)
	{
		if (node->value < current->value)
		{
			if (!target)
				target = current;
			else if (target->value > current->value)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = get_lowest(a);
	return (target);
}

void	set_position(t_stack_node *stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack);
	while (stack)
	{
		stack->index = i;
		if (i <= len / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	int				cost;

	cheapest = NULL;
	cost = INT_MAX;
	while (stack)
	{
		if (stack->cost < cost)
		{
			cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
