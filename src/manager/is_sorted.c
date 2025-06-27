/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:48 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:02:39 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top || stack->size <= 1)
		return (EXIT_FAILURE);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (EXIT_SUCCESS);
		current = current->next;
	}
	return (EXIT_FAILURE);
}
