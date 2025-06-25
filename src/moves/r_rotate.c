/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:57:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 22:32:31 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*r_rotate(t_stack *stack)
{
    t_stack	*tmp;

    if (!stack || !stack->next)  // Add this check
        return (stack);
    tmp = stack;
    while (stack->next->next)
        stack = stack->next;
    stack->next->next = tmp;
    tmp = stack->next;
    stack->next = NULL;
    return (tmp);
}

void	rra(t_push_swap *lst)
{
    if (!lst || !lst->a)  // Add this check
        return;
    lst->a = r_rotate(lst->a);
    ft_printf("rra\n");  // Remove the extra parameter
}

void	rrb(t_push_swap *lst)
{
    if (!lst || !lst->b)  // Add this check
        return;
    lst->b = r_rotate(lst->b);
    ft_printf("rrb\n");  // Remove the extra parameter
}

void	rrr(t_push_swap *lst)
{
    if (!lst)  // Add this check
        return;
    if (lst->a)
        lst->a = r_rotate(lst->a);
    if (lst->b)
        lst->b = r_rotate(lst->b);
    ft_printf("rrr\n");  // Remove the extra parameter
}