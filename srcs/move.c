/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:55:09 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 15:48:49 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	swap(t_node *node, char *str)
{
	int	temp_nb;
	int	temp_index;

	if (node == NULL || node->next == NULL)
		return ;
	temp_nb = node->nb;
	node->nb = node->next->nb;
	node->next->nb = temp_nb;
	temp_index = node->index;
	node->index = node->next->index;
	node->next->index = temp_index;
	if (str)
		ft_printf("%s\n", str);
}

void	push(t_node **stack_src, t_node **stack_dest, char *str)
{
	t_node	*temp;

	if (*stack_src == NULL)
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
	if (str)
		ft_printf("%s\n", str);
}

void	rotate(t_node **stack, char *str)
{
	t_node	*old_head;
	t_node	*second_node;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	old_head = *stack;
	second_node = old_head->next;
	last = old_head;
	while (last->next != NULL)
		last = last->next;
	last->next = old_head;
	old_head->next = NULL;
	*stack = second_node;
	if (str)
		ft_printf("%s\n", str);
}

void	r_rotate(t_node **stack, char *str)
{
	t_node	*second_node;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_node = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_node = last;
		last = last->next;
	}
	second_node->next = NULL;
	last->next = *stack;
	*stack = last;
	if (str)
		ft_printf("%s\n", str);
}
