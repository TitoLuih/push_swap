/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 01:12:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/26 23:48:59 by lruiz-to         ###   ########.fr       */
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
    int	*cost_a;
    int	*cost_b;

    if (!lst || lst->size_b == 0)
        return;
        
    while (lst->size_b > 0)
    {
        costs = (int *)malloc(sizeof(int) * lst->size_b * 2);
        if (!costs)
            return;
        cost_a = costs;
        cost_b = costs + lst->size_b;
        calc_cost(lst, cost_a, cost_b);
        execute_cheapest_move(lst, cost_a, cost_b);
        
        free(costs);
    }
    final_rotation(lst);
}