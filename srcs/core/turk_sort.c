/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:46:40 by megrelli          #+#    #+#             */
/*   Updated: 2026/04/30 05:55:54 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	align_stack(t_stack_node **a)
{
	t_stack_node	*lowest;

	set_position(*a);
	lowest = get_lowest(*a);
	if (lowest->above_median == 1)
	{
		while (*a != lowest)
			ra(a);
	}
	else
	{
		while (*a != lowest)
			rra(a);
	}
}

void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*curr;

	if (stack_len(*a) > 3)
		pb(a, b);
	if (stack_len(*a) > 3)
		pb(a, b);
	while (stack_len(*a) > 3)
	{
		set_position(*a);
		set_position(*b);
		curr = *a;
		while (curr)
		{
			curr->target = get_target_in_b(curr, *b);
			curr->cost = get_push_cost(curr, stack_len(*a), stack_len(*b));
			curr = curr->next;
		}
		move_nodes(a, b, get_cheapest(*a));
		pb(a, b);
	}
	sort_three(a);
	return_to_a(a, b);
	align_stack(a);
}

int	get_push_cost(t_stack_node *node, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = 0;
	cost_b = 0;
	if (node->above_median == 1)
		cost_a = node->index;
	else
		cost_a = len_a - node->index;
	if (node->target->above_median == 1)
		cost_b = node->target->index;
	else
		cost_b = len_b - node->target->index;
	if (node->above_median == 1 && node->target->above_median == 1)
		return (ft_max(cost_a, cost_b));
	if (node->above_median == 0 && node->target->above_median == 0)
		return (ft_max(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

void	move_nodes(t_stack_node **a, t_stack_node **b, t_stack_node *c)
{
	if (c->above_median == 1 && c->target->above_median == 1)
	{
		while (*a != c && *b != c->target)
			rr(a, b);
	}
	else if (c->above_median == 0 && c->target->above_median == 0)
	{
		while (*a != c && *b != c->target)
			rrr(a, b);
	}
	while (c->above_median == 1 && *a != c)
		ra(a);
	while (c->above_median == 0 && *a != c)
		rra(a);
	while (c->target->above_median == 1 && *b != c->target)
		rb(b);
	while (c->target->above_median == 0 && *b != c->target)
		rrb(b);
}

void	return_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;

	while (*b)
	{
		set_position(*a);
		target = get_target_in_a(*b, *a);
		if (target->above_median == 1)
		{
			while (*a != target)
				ra(a);
		}
		else
		{
			while (*a != target)
				rra(a);
		}
		pa(a, b);
	}
}
