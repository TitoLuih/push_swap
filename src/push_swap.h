/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:15 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/03/13 15:58:30 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"

typedef struct p_s_stack
{
	int				*content;
	struct s_list	*next;
}	t_stack;

typedef struct push_swap
{
	p_s_stack *a;
	p_s_stack *b;
};


int	ft_error();

#endif