/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 01:12:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 22:42:39 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	final_rotation(t_push_swap *lst)
{
	int		min_node;
	int		min_pos;

	min_node = find_min(lst);
	min_pos = get_position(lst->a, min_node);
	if (min_pos <= lst->size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(lst);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < lst->size_a)
		{
			rra(lst);
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

    costs = (int *)malloc(sizeof(int) * lst->size_b * 2);
    if (!costs)
        return ;
    while (lst->size_b > 0)
    {
        cost_a = costs;
        cost_b = costs + lst->size_b;
        calc_cost(lst, cost_a, cost_b);
        cheapest_idx = find_cheapest_move(cost_a, cost_b, lst->size_b);
        execute_cheapest_move(lst, cost_a, cost_b);
    }
    free(costs);
    final_rotation(lst);
}