/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:48 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 21:23:41 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *list)
{
    t_stack	*temp;

    if (!list)
        return (EXIT_FAILURE);
    temp = list;
    while (temp && temp->next)
    {
        if (temp->value > temp->next->value)
            return (EXIT_FAILURE);
        temp = temp->next;
    }
    return (EXIT_SUCCESS);
}

int	is_one_num(t_stack *list)
{
	t_stack	*temp;
	int		count;

	temp = list;
	count = 0;
	while (temp->next)
		count++;
	if (count <= 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
