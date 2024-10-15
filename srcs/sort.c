/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:57:18 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/15 19:29:57 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort_b(t_node	**stack)
{
	t_node	*stack_b;

	stack_b = NULL;
	push(stack, &stack_b, "pb");
	push(stack, &stack_b, "pb");
	index_stack(stack);
	index_stack(&stack_b);
	ft_setarsa(*stack, stack_b);
	ft_setarsb(stack_b, *stack);
	ft_printf_stack(stack_b);
	ft_printf_stack(*stack);
	free_stack(stack_b);
}
