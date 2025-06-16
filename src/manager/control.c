/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/22 11:42:34 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ./push_swap 1 2 3 4 5 6
//./push_swap "12 5 1 2 3 4"
// !! ./push_swap "12 5 1 2 3 4" 9 23 434 43434 NO VALIDO 
// !! ./push_swap "  1232 12  12 12 1 " "1212 1212 " NO VALIDO
// !! ./push_swap "     " "12 1 121434 " NO VALIDO
// !! numeros duplicados no es aceptado

int	check_empty(char **str, int argc)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 1;
	i = 0;
	while (str[j][i] != '\0' && j <= argc - 1)
	{
		if (ft_isdigit(str[j][i]) != 1)
			check++;
		else if (str[j][i] != "\0" && j < argc - 1)
		{
			if (check == 0)
				return (EXIT_FAILURE);
			i = 0;
			j++;
		}
		else
			i ++;
	}
	if (check >= 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	check_for_doubles(t_push_swap *list)
{
	long long	temp;
	t_push_swap	*temp_ps;

	temp_ps = list;
	while (temp_ps)
	{
		temp = temp_ps->a->value;
		while (temp_ps)
		{
			if (temp_ps == temp)
				return (EXIT_FAILURE);
			else
				temp_ps->a->next;
		}
		temp_ps->a->next;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_valid(int argc, char **argv, t_push_swap *list)
{
	char	**splited;

	if (check_empty(argv, argc) == 1)
		return (ft_error("Empty arguments"));
	else if (argc == 2)
	{
		splited = ft_split(argv[1], " ");
		ft_stacker(argv, list, argc);
	}
	else if (argc >= 3)
		ft_stacker(argv, list, argc);
	if (check_for_doubles(list) == 1)
		return (ft_error("There are digits repeated"));
}
