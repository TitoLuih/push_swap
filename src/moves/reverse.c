/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:40 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/24 18:41:33 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*rotate(t_stack *a)
{
	t_stack	*temp;
	t_stack	*aux;

	temp = a;
	aux = a->next;
	while (temp->next)
		temp = temp->next;
	temp->next = a;
	a->next = NULL;
	return (aux);
}

void	ra(t_push_swap *list)
{
	list->a = rotate(list->a);
	ft_printf("ra\n");
}

void	rb(t_push_swap *list)
{
	list->a = rotate(list->b);
	ft_printf("rb\n");
}

void	rr(t_push_swap *list)
{
	list->a = rotate(list->a);
	list->b = rotate(list->b);
	ft_printf("rr\n");
}
