/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/25 17:50:56 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacker(int argc, char **argv, t_push_swap *list)
{
	int	i;
	char	**splited;

	i = 0;
	if (argc == 2)
		splited = ft_split(argv, " ");
	else
	{ 
		while (argv[i])
		{
			list->a->content = ft_atol(&argv[i]);
			list->a->next;
			i++;
		}
	}
	//!!error catcher 
	return(EXIT_SUCCESS);
}

int	ft_check_valid(int argc, char **argv, t_stack *list)
{
	ft_stacker(argc, argv, list);
}