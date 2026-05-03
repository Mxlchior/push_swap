/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:11:46 by megrelli          #+#    #+#             */
/*   Updated: 2026/05/01 03:17:04 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}	t_stack_node;

/* PARSING & INIT */
char			**parse_args(int argc, char **argv, int *is_split);
int				init_stack_a(t_stack_node **a, char **argv);
int				append_node(t_stack_node **stack, int n);

/* OPERATIONS */
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/* ALGO*/
void			turk_sort(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			move_nodes(t_stack_node **a, t_stack_node **b, t_stack_node *c);
void			return_to_a(t_stack_node **a, t_stack_node **b);
void			set_position(t_stack_node *stack);
int				get_push_cost(t_stack_node *node, int len_a, int len_b);
t_stack_node	*get_target_in_b(t_stack_node *node, t_stack_node *b);
t_stack_node	*get_target_in_a(t_stack_node *node, t_stack_node *a);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*get_highest(t_stack_node *stack);
t_stack_node	*get_lowest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
int				is_sorted(t_stack_node **a);
int				ft_max(int a, int b);

/* CLEAN*/
int				ft_error(t_stack_node **a);
void			ft_free_stack(t_stack_node **stack);
void			ft_free_tab(char **tab);

#endif