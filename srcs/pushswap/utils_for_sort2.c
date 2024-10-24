/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:56:05 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/21 10:57:43 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	reverse_stack(t_node **stack, int i)
{
	int	size;

	size = ft_lstsize_stack(*stack);
	index_stack(stack);
	if (i == 1)
	{
		while (!ft_is_reverse_sorted(*stack))
			r_rotate(stack, "rrb");
	}
	else
	{
		while (!ft_is_sorted(*stack))
			r_rotate(stack, "rra");
	}
}
