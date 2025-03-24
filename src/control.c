/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/24 15:40:44 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacker(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		 
	}
}

int	ft_check_valid(int argc, char **argv)
{
	if (argc == 1)
		return(EXIT_FAILURE);
	else if (argc == 2)
	{
		//check si esta bien o no el input, si esta bien split
	}
	else
	{
		//que coja todos los numeros, si son char pasarlos a int y al stack A
		ft_stacker();
	}
}