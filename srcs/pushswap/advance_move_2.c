/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_move_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:54:59 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/18 16:56:17 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	nrr(t_node **A, t_node **B, int n)
{
	while (n > 0)
	{
		rr(A, B);
		n--;
	}
}

void	nrrr(t_node **A, t_node **B, int n)
{
	while (n > 0)
	{
		rrr(A, B);
		n--;
	}
}

void	nrotate(t_node **stack, char *str, int n)
{
	while (n > 0)
	{
		rotate(stack, str);
		n--;
	}
}

void	nr_rotate(t_node **stack, char *str, int n)
{
	while (n > 0)
	{
		r_rotate(stack, str);
		n--;
	}
}
