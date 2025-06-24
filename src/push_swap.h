/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/24 18:37:30 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	long long int	value;
	int				cost;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int size_a;
	int top_a;
	int size_b;
	int top_b;
}	t_push_swap;

int		ft_check_valid(int argc, char **argv, t_push_swap *list);
long	ft_atol(char *num);
int		ft_stack_size(t_stack *stack);
int		ft_is_sorted(t_stack *list);
t_stack	*stack_new(long long int content);
int		ft_stacker(char **argv, t_push_swap *list, int argc);
void	ft_free_stack(t_push_swap *ps);
int		is_one_num(t_stack *list);
void	pa(t_push_swap *lst);
void	pb(t_push_swap *lst);
void	sa(t_push_swap *lst);
void	sb(t_push_swap *lst);
void	ss(t_push_swap *lst);
void	rra(t_push_swap *lst);
void	rrb(t_push_swap *lst);
void	rrr(t_push_swap *lst);
void	ra(t_push_swap *lst);
void	rb(t_push_swap *lst);
void	rr(t_push_swap *lst);
void	sort_three(t_push_swap *lst);
void	sort_two(t_push_swap *lst);
void	execute_move(t_push_swap *lst, int cost_a, int cost_b);
void	cost_algorithm(t_push_swap *lst);
void	calc_cost(t_push_swap *lst, int *cost_a, int *cost_b);
int		find_target_position(t_push_swap *lst, int b_value);
void	execute_cheapest_move(t_push_swap *lst, int *cost_a, int *cost_b);
int		find_min(t_push_swap *lst);
int		get_position(t_stack *stack, int value);
int		find_cheapest_move(int *cost_a, int *cost_b, int size);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int n);
#endif