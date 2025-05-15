/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:41:52 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/15 12:42:32 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_push_swap *ps)
{
	t_stack	*temp;

	while (ps->a)
	{
		temp = ps->a;
		ps->a = ps->a->next;
		free(temp);
	}
	while (ps->b)
	{
		temp = ps->b;
		ps->b = ps->b->next;
		free(temp);
	}
	free(ps);
}
