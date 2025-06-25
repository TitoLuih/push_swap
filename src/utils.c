/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:24:55 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 21:32:16 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *num)
{
	long long int	res;
	long			sign;
	int				cont;

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

t_stack	*stack_new(long long int content)
{
	t_stack	*n;

	n = (t_stack *) malloc (sizeof(t_stack));
	if (!n)
		return (NULL);
	n->value = content;
	n->next = NULL;
	return (n);
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