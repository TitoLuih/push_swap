/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 21:08:12 by lruiz-to         ###   ########.fr       */
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
		    return (ft_error("Memory allocation failed"));
		lst->a = NULL;  // Add these initializations
		lst->b = NULL;
		lst->size_a = 0;
		lst->size_b = 0;
		ft_printf("main1\n");
		if (control(argc, argv, lst) == EXIT_FAILURE)
		{
		    ft_freemen(lst);
		    return (ft_error(""));
		}
		ft_printf("main2\n");
		if (lst->a && !ft_is_sorted(lst->a))
		    push_swap_algorithm(lst);
		ft_freemen(lst);
    }
    else if (argc != 1)
        return (ft_error(""));
        
    return (EXIT_SUCCESS);
}