/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/24 19:21:23 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*lst;

	if (argc >= 2)
	{
		lst = ft_calloc(1, sizeof(t_push_swap));
		if (control(argc, argv, lst) == EXIT_FAILURE)
			return (ft_freemen(lst), print_error());
		ft_push_swap(lst);
		ft_freemen(lst);
	}
	else
	{
		if (argc == 1)
			return (EXIT_SUCCESS);
		else
			return (print_error());
	}
	return (EXIT_SUCCESS);
}