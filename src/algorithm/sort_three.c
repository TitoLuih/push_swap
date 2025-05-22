/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:05 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/22 11:45:33 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest_value(t_stack *stack)
{
	int	biggest;

	biggest = stack->value;
	while (stack)
	{
		if (stack->value > biggest)
			biggest = stack->value;
		stack->next;
	}
	return (biggest);
}

void	sort_three(t_push_swap *list)
{
	t_push_swap	*temp_ps;
	int			big_poppa;

	big_poppa = biggest_value(list->a);
	if (list->a->value == big_poppa)
		ra (list);
	else if (list->a->next->value == big_poppa)
		rra (list);
	else if (list->a->value > list->a->next->value)
		sa (list);
}
