/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:55:09 by kduroux           #+#    #+#             */
/*   Updated: 2024/09/30 13:55:10 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	swap(t_node *node)
{
	int	temp_nb;
	int	temp_index;

	temp_nb = node->nb;
	node->nb = node->next->nb;
	node->next->nb = temp_nb;
	temp_index = node->index;
	node->index = node->next->index;
	node->next->index = temp_index;
}

void	push(t_node **stack_A, t_node **stack_B)
{
	t_node	*temp;

	temp = *stack_B;
	*stack_B = (*stack_B)->next;
	temp->next = *stack_A;
	*stack_A = temp;
}
