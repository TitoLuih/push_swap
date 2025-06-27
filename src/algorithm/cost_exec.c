/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:00:39 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:06:21 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_combined_rotations(t_stack *a, t_stack *b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_individual_rotations(t_stack *a, t_stack *b, int cost_a,
		int cost_b)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	do_combined_rotations(a, b, &cost_a, &cost_b);
	do_individual_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	cheapest_idx;

	cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
	execute_move(a, b, cost_a[cheapest_idx], cost_b[cheapest_idx]);
}
