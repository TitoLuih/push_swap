/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/04/23 18:05:01 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_empty(char **str, int argc)
{
	int i;
	int j;
	int check;

	check = 0;
	j = 1;
	i = 0;
	while (str[j][i] != '\0' && j <= argc - 1)
	{
		if (str[j][i] != " ")
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

int	ft_stacker(char **argv, t_push_swap *list, int argc)
{
	int	i;
	int cont;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i]) 
	{
		cont = 0;
		while (cont <= ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][cont]) == 1)
				return (EXIT_FAILURE);
			cont++;	
		}
		list->a->content = ft_atol(&argv[i]);
		list->a = list->a->next;
		i++;
	}
	if (!list)
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

int	ft_check_valid(int argc, char **argv, t_push_swap *list)
{
	char **splited;

	if (check_empty(argv, argc) == 1)
		return(ft_error("Empty arguments"));
	if (argc == 2)
	{
		splited = ft_split(argv[1], " ");
		ft_stacker(splited, list, argc);
	}
	else
		ft_stacker(argv, list, argc);
}
