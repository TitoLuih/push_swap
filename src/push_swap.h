/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/22 11:41:32 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	long long int	value;
	int				cost;
	int				index;
	bool			below;
	struct s_stack	*obj_node;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
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

#endif