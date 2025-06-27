/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:24:24 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:06:37 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_operation(t_stack *dst, t_stack *src)
{
	t_node	*temp;

	if (src->size == 0)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dst->top;
	dst->top = temp;
	src->size--;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push_operation(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push_operation(b, a);
	ft_printf("pb\n");
}
