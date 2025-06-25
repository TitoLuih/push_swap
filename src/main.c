/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 21:21:12 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*lst;

	if (argc >= 2)
	{
		lst = ft_calloc(1, sizeof(t_push_swap));
		if (!lst)
		    return (ft_error(""));
		lst->a = NULL;		lst->b = NULL;
		lst->size_a = 0;
		lst->size_b = 0;
		if (control(argc, argv, lst) == EXIT_FAILURE)
		{
		    ft_freemen(lst);
		    return (ft_error(""));
		}
		if (lst->a && ft_is_sorted(lst->a) == EXIT_FAILURE)
		    push_swap_algorithm(lst);
		ft_freemen(lst);
    }
    else if (argc != 1)
        return (ft_error(""));
        
    return (EXIT_SUCCESS);
}