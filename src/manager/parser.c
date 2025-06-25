/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:27:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 20:56:27 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stacker(char **argv, t_push_swap *list, int argc)
{
    int		i;
    t_stack	*new_node;
    t_stack	*head;

    i = 1;
    if (!list)
        return (EXIT_FAILURE);
    list->a = NULL;
    list->size_a = 0;
    while (i < argc)
    {
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return (EXIT_FAILURE);
        new_node->value = ft_atol(argv[i]);
        new_node->next = NULL;
        
        if (list->a == NULL)
        {
            list->a = new_node;
            head = list->a;
        }
        else
        {
            list->a->next = new_node;
            list->a = list->a->next;
        }
        list->size_a++;
        i++;
    }
    list->a = head;
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
}