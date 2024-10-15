/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:06:36 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/14 11:07:35 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_lstsize_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_node	*ft_lstlast_stack(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	index_stack(t_node **stack)
{
	t_node	*head;
	int		i;
	int		j;

	i = 0;
	j = 1;
	head = *stack;
	while (head)
	{
		head->index = i;
		i++;
		j++;
		head = head->next;
	}
}
