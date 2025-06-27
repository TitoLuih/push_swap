/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:05 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/26 00:28:43 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_push_swap *lst)
{
    int	first;
    int	second;
    int	third;

    if (!lst || !lst->a || !lst->a->next || !lst->a->next->next)  // Add this check
        return;
    first = lst->a->value;
    second = lst->a->next->value;
    third = lst->a->next->next->value;
    if (first > second && second < third && first < third)
        sa(lst);
    else if (first > second && second > third)
    {
        sa(lst);
        rra(lst);
    }
    else if (first > second && second < third && first > third)
        ra(lst);
    else if (first < second && second > third && first < third)
    {
        sa(lst);
        ra(lst);
    }
    else if (first < second && second > third && first > third)
        rra(lst);
}

void	sort_two(t_push_swap *lst)
{
	if (lst->a->value > lst->a->next->value)
		sa(lst);
}

void	push_swap_algorithm(t_push_swap *lst)
{
    if (lst->size_a <= 1)
        return;
    if (lst->size_a == 2)
        sort_two(lst);
    else if (lst->size_a == 3)
        sort_three(lst);
    else
    {
        while (lst->size_a > 3)
            pb(lst);
        if (!ft_is_sorted(lst->a))
            sort_three(lst);
        cost_algorithm(lst);
    }
}