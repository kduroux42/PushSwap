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

void	swap(t_node *node, char *str)
{
	int	temp_nb;
	int	temp_index;

	if (!node)
		return ;
	temp_nb = node->nb;
	node->nb = node->next->nb;
	node->next->nb = temp_nb;
	temp_index = node->index;
	node->index = node->next->index;
	node->next->index = temp_index;
	ft_printf("%s\n", str);
}

void	push(t_node **stack_src, t_node **stack_dest, char *str)
{
	t_node	*temp;

	if (!stack_src)
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
	ft_printf("%s\n", str);
}

void	rotate(t_node **stack, char *str)
{
	t_node	*old_head;
	t_node	*second_node;
	t_node	*last;

	old_head = *stack;
	second_node = old_head->next;
	last = old_head;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	last->next = old_head;
	old_head->next = NULL;
	*stack = second_node;
	ft_printf("%s\n", str);
}
