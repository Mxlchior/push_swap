/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:33:42 by megrelli          #+#    #+#             */
/*   Updated: 2026/04/30 02:48:18 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack_node	*get_highest(t_stack_node *stack)
{
	t_stack_node	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (highest->value < stack->value)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack_node	*get_lowest(t_stack_node *stack)
{
	t_stack_node	*lowest;

	if (!stack)
		return (NULL);
	lowest = stack;
	while (stack)
	{
		if (stack->value < lowest->value)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

int	is_sorted(t_stack_node **a)
{
	int				sorted;
	t_stack_node	*temp;

	if (!(*a))
		return (1);
	sorted = 1;
	temp = *a;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			sorted = 0;
		temp = temp->next;
	}
	return (sorted);
}

int	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (1);
	new_node->value = n;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	return (0);
}
