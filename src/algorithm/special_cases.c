/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:05 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/24 18:36:34 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_push_swap *lst)
{
	int	first;
	int	second;
	int	third;

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
