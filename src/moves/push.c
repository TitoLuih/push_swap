/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:24:24 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 21:46:17 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_push_swap *lst)
{
    t_stack	*tmp;

    if (!lst || !lst->b)
        return;
    tmp = lst->b->next;
    lst->b->next = lst->a;
    lst->a = lst->b;
    lst->b = tmp;
    lst->size_a++;
    lst->size_b--;
    ft_printf("pa\n");
}

void	pb(t_push_swap *lst)
{
    t_stack	*tmp;

    if (!lst || !lst->a)
        return;
    tmp = lst->a->next;
    lst->a->next = lst->b;
    lst->b = lst->a;
    lst->a = tmp;
    lst->size_a--;
    lst->size_b++;
    ft_printf("pb\n");
}
