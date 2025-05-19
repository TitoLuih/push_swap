/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/19 11:19:24 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ./push_swap 1 2 3 4 5 6
//./push_swap "12 5 1 2 3 4"
// !! ./push_swap "12 5 1 2 3 4" 9 23 434 43434 NO VALIDO 
// !! ./push_swap "  1232 12  12 12 1 " "1212 1212 " NO VALIDO
// !! ./push_swap "     " "12 1 121434 " NO VALIDO
 
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

int check_for_doubles(t_push_swap *list)
{
	int temp;
	t_push_swap *temp_ps;
	
	temp_ps = list;
	while (list->a->next)
	{
		temp = temp_ps->a->content;
		while(temp_ps)
		{
			if (temp_ps == temp)
				return(EXIT_FAILURE);
			else
				temp_ps->a->next;
		}
	}
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
		ft_error("There are digits repeated");
}
