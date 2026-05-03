/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:31:51 by megrelli          #+#    #+#             */
/*   Updated: 2026/04/30 00:13:26 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_to_push;

	if (!src || !*src || !dest)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->next = *dest;
	node_to_push->prev = NULL;
	if (*dest)
		(*dest)->prev = node_to_push;
	*dest = node_to_push;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
