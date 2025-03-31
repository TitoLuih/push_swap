/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:32:50 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/31 15:33:44 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(long long int content)
{
	t_stack	*x;

	x = (t_stack *) malloc (sizeof(t_stack));
	if (!x)
		return (NULL);
	x->content = content;
	x->next = NULL;
	return (x);
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}