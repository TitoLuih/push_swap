/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/04/21 13:30:08 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
	if (argc == 2)
	{
		splited = ft_split(argv[1], " ");
		ft_stacker(splited, list, argc);
	}
	else
		ft_stacker(argv, list, argc);
}