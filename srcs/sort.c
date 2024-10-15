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
	/*
	t_node	*stack_b;

	stack_b = NULL;
	*/

	if (ft_lstsize_stack(*stack) == 2)
		swap(*stack, "sa");
	*stack = weight_stack_a(stack);
	ft_printf_stack(*stack);
}

t_node	*weight_stack_a(t_node **stack)
{
	t_node	*head;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 1;
	size = ft_lstsize_stack(*stack) / 2;
	head = *stack;
	(*stack)->index = 0;
	(*stack)->weight_a = 0;
	while (*stack)
	{
		if (i > size)
			j--;
		else
			j++;
		if (i == 0)
			j = 1;
		(*stack)->weight_a = j;
		(*stack)->index = i + 1;
		i++;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (*stack);
}
