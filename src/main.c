/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/22 11:42:58 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO Si no se especifican parámetros,
//TODO el programa no deberá mostrar nada y 
//TODO deberá devolver el control al usuario
int	main(int argc, char *argv)
{
	t_push_swap	*list;

	if (argc >= 2)
	{
		list = malloc(sizeof(t_push_swap));
		ft_check_valid(argc, argv, list);
	}
	else
		ft_error("Not enough arguments");
}
