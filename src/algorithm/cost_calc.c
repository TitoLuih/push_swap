/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:40:42 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/17 01:35:20 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_closest_bigger(t_push_swap *lst, int b_value, int *pos)
{
	t_stack	*temp_a;
	int		closest_val;
	int		i;

	temp_a = lst->a;
	closest_val = INT_MAX;
	*pos = -1;
	i = 0;
	while (i < lst->size_a)
	{
		if (lst->a->value > b_value && lst->a->value < closest_val)
		{
			closest_val = lst->a->value;
			*pos = i;
		}
		lst->a = lst->a->next;
		i++;
	}
}



void	calc_cost(t_push_swap *lst, int *cost_a, int *cost_b)
{
	int target;
	int i;
	t_stack *b_temp;
    
	i = 0;
	b_temp = lst->b;
	while (i < lst->size_b)
    {
        if (i <= lst->size_b / 2)
            cost_b[i] = i;
        else
			cost_b[i] = i - lst->size_b;
		target = find_target(lst, b_temp->value);
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
	find_closest_bigger(lst->a, b_value, &closest_bigger_pos);
	find_min_value(lst->a, &min_pos);
	if (closest_bigger_pos == -1)
		return (min_pos);
	return (closest_bigger_pos);
}