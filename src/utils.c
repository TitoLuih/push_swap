/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:24:55 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 09:15:50 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	long long int	n;
	int				sign;
	int				i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*lst_new(long long int content)
{
	t_stack	*x;

	x = (t_stack *) malloc (sizeof(t_stack));
	if (!x)
		return (NULL);
	x->value = content;
	x->next = NULL;
	return (x);
}

int	find_min(t_push_swap *lst)
{
	t_stack	*current;
	int min;
	long long int temp;

	if (!lst->a)
		return (EXIT_FAILURE);
	current = lst->a;
	temp = current->value;
	while (current)
	{
		if (current->value < temp)
			temp = current->value;
		current = current->next;
	}
	return (temp);
}

void	ft_freemen(t_push_swap *lst)
{
	t_stack	*tmp;

	while (lst->a)
	{
		tmp = lst->a;
		lst->a = lst->a->next;
		free(tmp);
	}
	while (lst->b)
	{
		tmp = lst->b;
		lst->b = lst->b->next;
		free(tmp);
	}
	free(lst);
}