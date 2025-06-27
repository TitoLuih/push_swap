/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:20 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 13:03:50 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	if (parse_arguments(argc, argv, a) == EXIT_FAILURE)
	{
		free_stack(a);
		return (error_exit(NULL), 0);
	}
	if (has_duplicates(a) == EXIT_SUCCESS)
	{
		free_stack(a);
		error_exit(NULL);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!init_stacks(argc, argv, &stack_a, &stack_b))
		return (0);
	if (is_sorted(&stack_a) == EXIT_FAILURE)
		return (free_stack(&stack_a), 0);
	push_swap_algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
