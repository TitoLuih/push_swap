/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/20 19:50:22 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stacker(char **argv, t_push_swap *list, int argc)
{
	int	i;
	int	cont;

	i = 1;
	while (argv[i])
	{
		cont = 0;
		while (cont <= ft_strlen(argv[i]))
		{
			//TODO crear funcion que acepte numeros negativos
			if (ft_isdigit(argv[i][cont]) == 1)
				return (EXIT_FAILURE);
			cont++;
		}
		list->a->value = ft_atol(argv[i]);
		list->a = list->a->next;
		i++;
	}
	if (!list)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
