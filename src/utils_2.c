/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:06:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 09:13:57 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int value)
{
	t_stack	*current;
	int		position;

	if (!stack)
		return (-1);
	current = stack;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (EXIT_FAILURE);
}