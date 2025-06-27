/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/27 09:14:17 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stacker(char **argv, t_push_swap *list, int argc)
{
    int		i;
    t_stack	*new_node;
    t_stack	*current;
    long	value;

    i = 0;
    if (!list)
        return (EXIT_FAILURE);
    list->a = NULL;
    list->size_a = 0;
    current = NULL;
    while (i < argc)
    {
        value = ft_atol(argv[i]);
        if (value > INT_MAX)
            return (EXIT_FAILURE);
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return (EXIT_FAILURE);
        new_node->value = (int)value;
        new_node->next = NULL;
        if (list->a == NULL)
        {
            list->a = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        list->size_a++;
        i++;
    }
    return (EXIT_SUCCESS);
}

static int	is_separator(char c, char sep)
{
    return (c == sep);
}

int	ft_count_words(char const *str, char sep)
{
    int	count;
    int	i;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && is_separator(str[i], sep))
            i++;
        if (str[i])
            count++;
        while (str[i] && !is_separator(str[i], sep))
            i++;
    }
    return (count);
}static int	ft_decomprime(char *str, t_push_swap *lst, int i)
{
	char	**res;
	t_stack	*tmp;

	res = ft_split(str, ' ');
	if (ft_check_util(res, i) == EXIT_FAILURE)
		return (ft_free_split(res));
	lst->a = lst_new(ft_atol(res[0]));
	tmp = lst->a;
	i = 0;
	while (res[++i])
	{
		if (!tmp)
			return (ft_free_split(res));
		tmp->next = lst_new(ft_atol(res[i]));
		if (!tmp->next)
			return (ft_free_split(res));
		tmp = tmp->next;
	}
	i = -1;
	ft_free_split(res);
	return (EXIT_SUCCESS);
}

static int	ft_init(char **str, t_push_swap *lst, int i)
{
	t_stack	*tmp;

	if (ft_check_util(str, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	lst->a = lst_new(ft_atol(str[1]));
	tmp = lst->a;
	i = 1;
	while (str[++i])
	{
		if (!tmp)
			return (EXIT_FAILURE);
		tmp->next = lst_new(ft_atol(str[i]));
		if (!tmp->next)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_isinputvalid(char **input)
{
	int	i;

	i = 1;
	while (input[i])
	{
		if (input[i][0] == '\0')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_checkforvalidlst(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a)
	{
		tmp = a->next;
		if (a->value > INT_MAX || a->value < INT_MIN)
			return (EXIT_FAILURE);
		while (tmp)
		{
			if (a->value == tmp->value)
				return (EXIT_FAILURE);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (EXIT_SUCCESS);
}

int	control(int argc, char **input, t_push_swap *lst)
{
	if (ft_isinputvalid(input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		if (ft_decomprime(input[1], lst, -1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		if (ft_init(input, lst, 0) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (ft_checkforvalidlst(lst->a) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}