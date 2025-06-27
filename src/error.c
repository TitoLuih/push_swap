/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:41:10 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:06:45 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	else
		ft_putendl_fd("Error", 2);
	exit(1);
}
