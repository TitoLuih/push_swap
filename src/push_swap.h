/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/04/10 16:07:17 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"

typedef struct s_stack
{
	long long int	content;
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

int		ft_check_valid(int argc, char **argv, t_stack *list);
long	ft_atol(char *num);

void ft_free_stack(t_push_swap *ps);

//moves functions
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