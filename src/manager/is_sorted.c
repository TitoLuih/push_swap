/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:48 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/15 12:45:35 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (EXIT_FAILURE);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
