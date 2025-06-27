/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:05:40 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

int		get_position(t_stack *stack, int value);
void	error_exit(char *message);
t_node	*create_node(int value);
void	add_to_bottom(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
int		parse_arguments(int argc, char **argv, t_stack *stack);
void	push_swap_algorithm(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
int		is_sorted(t_stack *stack);
void	cost_algorithm(t_stack *a, t_stack *b);
t_node	*find_min(t_stack *stack);
void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b);
int		find_target_position(t_stack *a, int b_value);
void	calculate_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
int		find_cheapest_move(int *cost_a, int *cost_b, int size);
void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		free_split(char **split);
void	sort_three(t_stack *a);
void	sort_two(t_stack *a);
int		parse_arguments(int argc, char **argv, t_stack *stack_a);
void	sort_five(t_stack *a, t_stack *b);
int		find_target_position(t_stack *a, int b_value);
void	calculate_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
int		find_cheapest_move(int *cost_a, int *cost_b, int size);
void	cost_algorithm(t_stack *a, t_stack *b);
long	ft_atol(const char *str);
int		stack_len(t_stack *stack);
int		get_position(t_stack *stack, int value);

#endif