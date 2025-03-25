/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:24:55 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/25 14:27:08 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *num)
{
	long	res;
	long	sign;
	int		cont;

	res = 0;
	cont = 0;
	sign = 1;
	while (num[cont] == 32 || (num[cont] >= 9 && num[cont] <= 13))
		cont++;
	if (num[cont] == '+' && num[cont +1] != '-')
		cont++;
	if (num[cont] == '-')
	{
		sign = sign * -1;
		cont++;
	}
	while (ft_isdigit(num[cont]))
	{
		res = (res * 10) + (num[cont] - 48);
		cont++;
	}
	return (res * sign);
}
