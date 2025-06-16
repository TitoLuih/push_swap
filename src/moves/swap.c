/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:24:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/15 12:46:28 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*swap(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	tmp->next = stack->next;
	stack->next = tmp;
	return (stack);
}

void	sa(t_push_swap *lst)
{
	lst->a = swap(lst->a);
	ft_printf("sa\n");
}

void	sb(t_push_swap *lst)
{
	lst->b = swap(lst->b);
	ft_printf("sb\n");
}

void	ss(t_push_swap *lst)
{
	lst->a = swap(lst->a);
	lst->b = swap(lst->b);
	ft_printf("ss\n");
}
