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
#include <stdio.h>

void swap(t_node *node)
{
	int temp_nb;
	int temp_index;

	if (!node)
		return;
	temp_nb = node->nb;
	node->nb = node->next->nb;
	node->next->nb = temp_nb;
	temp_index = node->index;
	node->index = node->next->index;
	node->next->index = temp_index;
}

void push(t_node **stack_src, t_node **stack_dest)
{
	t_node *temp;

	if (!stack_src)
		return;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
}

void free_stack(t_node *stack)
{
    t_node *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

t_node *create_stack(int ac, char **av, char *str)
{
	int		i;
	char	**res;
	t_node	*stack;
	t_node	*new_node;
	t_node	*head;

	(void)av;
	(void)ac;
	i = 0;
	res = ft_split(str, ' ');
	stack = malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->nb = ft_atoi(res[i]);
	stack->next = NULL;
	head = stack;
	i++;
	while (res[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(res[i]);
		new_node->next = NULL;
		stack->next = new_node;
		stack = new_node;
		i++;
	}
	free_split(res);
	return (head);
}
