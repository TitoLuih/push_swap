/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:06:33 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	if (!str || !str[0])
		return (EXIT_FAILURE);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;
	int		i;
	int		j;

	if (!stack->top || stack->size <= 1)
		return (EXIT_FAILURE);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		checker = current->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (current->value == checker->value)
				return (EXIT_SUCCESS);
			checker = checker->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (EXIT_FAILURE);
}

int	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (EXIT_FAILURE);
}

static int	parse_and_add(char **args, t_stack *stack_a)
{
	int	j;

	j = 0;
	while (args[j])
	{
		if (is_valid_number(args[j]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		add_to_bottom(stack_a, create_node(ft_atoi(args[j])));
		j++;
	}
	return (EXIT_SUCCESS);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
			return (free_split(split));
		if (parse_and_add(split, stack_a) == EXIT_FAILURE)
			return (free_split(split));
		free_split(split);
	}
	else
	{
		if (parse_and_add(&argv[1], stack_a) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
