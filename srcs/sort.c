/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:57:18 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 18:40:27 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort(t_node	**stack)
{
	t_node	*stack_b;

	stack_b = NULL;

	if (ft_lstsize_stack(*stack) == 2)
		swap(*stack, "sa");
}

void	weight_stack_a(t_node **stack)
{
	(*stack)->index = 1;
	(*stack)->weight_a = 1;
	while (*stack)
	{
		if ((*stack)->index > ft_lstsize_stack(*stack) / 2 )
			(*stack)->weight_a--;
		(*stack)->weight_a++;
		(*stack)->index++;
		*stack = (*stack)->next;
	}
}
