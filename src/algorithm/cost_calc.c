/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:40:42 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 22:40:59 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_closest_bigger(t_push_swap *lst, int b_value, int *pos)
{
    t_stack	*temp_a;
    int		closest_val;
    int		i;

    if (!lst || !lst->a)  // Add this check
    {
        *pos = -1;
        return;
    }
    
    temp_a = lst->a;
    closest_val = INT_MAX;
    *pos = -1;
    i = 0;
    while (i < lst->size_a && temp_a)  // Add temp_a check
    {
        if (temp_a->value > b_value && temp_a->value < closest_val)
        {
            closest_val = temp_a->value;
            *pos = i;
        }
        temp_a = temp_a->next;
        i++;
    }
}

static void	find_min_value(t_push_swap *lst, int *pos)
{
    t_stack	*temp_a;
    int		min_val;
    int		i;

    if (!lst || !lst->a)
    {
        *pos = -1;
        return;
    }
    temp_a = lst->a;
    min_val = INT_MAX;
    *pos = -1;
    i = 0;
    while (i < lst->size_a && temp_a)
    {
        if (temp_a->value < min_val)
        {
            min_val = temp_a->value;
            *pos = i;
        }
        temp_a = temp_a->next;
        i++;
    }
}

int	find_cheapest_move(int *cost_a, int *cost_b, int size)
{
	int	min_cost;
	int	min_index;
	int	total_cost;
	int	i;

	min_cost = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < size)
	{
		if ((cost_a[i] > 0 && cost_b[i] > 0) || (cost_a[i] < 0
				&& cost_b[i] < 0))
			total_cost = ft_max(ft_abs(cost_a[i]), ft_abs(cost_b[i]));
		else
			total_cost = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	calc_cost(t_push_swap *lst, int *cost_a, int *cost_b)
{
    int target;
    int i;
    t_stack *b_temp;
    
    i = 0;
    b_temp = lst->b;
    while (i < lst->size_b && b_temp)  // Add b_temp check here
    {
        if (i <= lst->size_b / 2)
            cost_b[i] = i;
        else
            cost_b[i] = i - lst->size_b;
        target = find_target_position(lst, b_temp->value);
        if (target <= lst->size_a / 2)
            cost_a[i] = target;
        else
            cost_a[i] = target - lst->size_a;
        b_temp = b_temp->next;
        i++;
    }
}

int	find_target_position(t_push_swap *lst, int b_value)
{
	int	closest_bigger_pos;
	int	min_pos;

	if (lst->size_a == 0)
		return (0);
	find_closest_bigger(lst, b_value, &closest_bigger_pos);
	find_min_value(lst, &min_pos);
	if (closest_bigger_pos == -1)
		return (min_pos);
	return (closest_bigger_pos);
}