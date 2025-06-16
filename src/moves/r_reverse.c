/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:57:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/15 12:46:52 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*r_rotate(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack->next->next)
		stack = stack->next;
	stack->next->next = tmp;
	tmp = stack->next;
	stack->next = NULL;
	return (tmp);
}

void	rra(t_push_swap *lst)
{
	lst->a = r_rotate(lst->a);
	ft_printf("rra\n", 1);
}

void	rrb(t_push_swap *lst)
{
	lst->b = r_rotate(lst->b);
	ft_printf("rrb\n", 1);
}

void	rrr(t_push_swap *lst)
{
	lst->a = r_rotate(lst->a);
	lst->b = r_rotate(lst->b);
	ft_printf("rrr\n", 1);
}
