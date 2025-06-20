/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 01:12:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/17 22:30:21 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	final_rotation(t_push_swap *lst)
{
	t_node	*min_node;
	int		min_pos;

	min_node = find_min(lst);
	min_pos = get_position(lst->a, min_node->value);
	if (min_pos <= lst->size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(lst->a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < lst->size_a)
		{
			rra(lst->a);
			min_pos++;
		}
	}
}

void	cost_algorithm(t_push_swap *lst)
{
	int	*costs;
	int	cheapest_idx;
	int	*cost_a;
	int	*cost_b;

	//prepare_stacks(a, b);
	costs = (int *)malloc(sizeof(int) * lst->size_b * 2);
	if (!costs)
		error_exit(NULL);
	while (lst->size_b > 0)
	{
		cost_a = costs;
		cost_b = costs + lst->size_b;
		calculate_cost(lst->a, lst->b, cost_a, cost_b);
		cheapest_idx = find_cheapest_move(cost_a, cost_b, lst->size_b);
		execute_cheapest_move(lst->a, lst->b, cost_a, cost_b);
	}
	free(costs);
	final_rotation(lst);
}