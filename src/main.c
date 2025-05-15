/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/15 12:42:21 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv)
{
	t_push_swap	*list;

	if (argc >= 2)
	{
		list = ft_calloc(1, sizeof(t_push_swap));
		ft_check_valid(argc, argv, list);
	}
	else
		ft_error("Not enough arguments");
}
