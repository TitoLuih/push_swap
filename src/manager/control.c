/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:11:00 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/06/25 22:29:20 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ./push_swap 1 2 3 4 5 6
//./push_swap "12 5 1 2 3 4"
// !! ./push_swap "12 5 1 2 3 4" 9 23 434 43434 NO VALIDO 
// !! ./push_swap "  1232 12  12 12 1 " "1212 1212 " NO VALIDO
// !! ./push_swap "     " "12 1 121434 " NO VALIDO
// !! numeros duplicados no es aceptado

int	control(int argc, char **argv, t_push_swap *lst)
{
	if (ft_check_valid(argc, argv, lst) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_empty(char **str, int argc)
{
    int	j;
    int	has_digit;

    j = 1;
    while (j < argc)
    {
        int i = 0;
        has_digit = 0;
        while (str[j][i])
        {
            if (ft_isdigit(str[j][i]) || 
                (i == 0 && (str[j][i] == '-' || str[j][i] == '+') && 
                ft_isdigit(str[j][i + 1])))
                has_digit = 1;
            i++;
        }
        if (!has_digit)
            return (EXIT_FAILURE);
        j++;
    }
    return (EXIT_SUCCESS);
}

int	check_for_doubles(t_push_swap *list)
{
    t_stack	*current;
    t_stack	*checker;

    current = list->a;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (checker->value == current->value)
                return (EXIT_FAILURE);
            checker = checker->next;
        }
        current = current->next;
    }
    return (EXIT_SUCCESS);
}

int	ft_check_valid(int argc, char **argv, t_push_swap *list)
{
    char	**splited;

    if (check_empty(argv, argc) == EXIT_FAILURE)
        return (ft_error("Empty arguments"));
    else if (argc == 2)
    {
        splited = ft_split(argv[1], ' ');
        if (!splited)
            return (ft_error("Split failed"));
        if (ft_stacker(splited, list, ft_count_words(argv[1], ' ') + 1) == EXIT_FAILURE)
        {
            ft_free_split(splited);
            return (ft_error("Stacking failed"));
        }
        ft_free_split(splited);
    }
    else if (argc >= 3)
        if (ft_stacker(argv, list, argc) == EXIT_FAILURE)
            return (ft_error("Stacking failed"));
    if (check_for_doubles(list) == EXIT_FAILURE)  // Fix: was == 1
        return (ft_error("There are digits repeated"));
    return (EXIT_SUCCESS);
}
