/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:43:54 by megrelli          #+#    #+#             */
/*   Updated: 2026/04/30 00:28:17 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest;

	if (!*a || !(*a)->next)
		return ;
	highest = get_highest(*a);
	if (highest == *a)
		ra(a);
	else if (highest == (*a)->next)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
