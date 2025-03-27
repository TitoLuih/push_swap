/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:24:24 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/27 15:40:20 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push_swap *lst)
{
	t_stack	*tmp;
	
	tmp = lst->a->next;
	lst->a->next = lst->b;
	lst->b = lst->a;
	lst->a = tmp;
	ft_printf("pb\n");
}

void	pa(t_push_swap *lst)
{
	t_stack	*tmp;
	
	tmp = lst->b->next;
	lst->b->next = lst->a;
	lst->a = lst->b;
	lst->b = tmp;
	ft_printf("pa\n");
}
