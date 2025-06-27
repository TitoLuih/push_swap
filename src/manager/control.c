/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 09:11:57 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_util(char **str, int i)
{
	int	j;

	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+')
			&& ft_isdigit(str[i][j + 1]) && !ft_isdigit(str[i][j - 1]))
				j++;
			else if (ft_isdigit(str[i][j]) == 0)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_for_doubles(t_push_swap *list)
{
    t_stack	*current;
    t_stack	*checker;

    current = list->a;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (checker->value == current->value)
                return (EXIT_FAILURE);
            checker = checker->next;
        }
        current = current->next;
    }
    return (EXIT_SUCCESS);
}

