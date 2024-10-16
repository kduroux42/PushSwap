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

void	sort_b(t_node	**a)
{
	t_node	*b;

	b = NULL;
	push(a, &b, "pb");
	push(a, &b, "pb");
	if (!ft_is_reverse_sorted(b))
		swap(b, "sb");
	ft_push_to_b(a, &b);
	/*
	ft_printf_stack(*a);
	ft_printf_stack(b);
	*/
	free_stack(b);
}


void	ft_find_cost(t_node	*a)
{
	t_node	*temp;
	int		size;

	temp = a;
	size = ft_lstsize_stack(a);
	while (temp)
	{
		if (temp->index <= size / 2)
			temp->cost = temp->index + temp->target->index;
		else if (temp->index == size - 1)
			temp->cost = 1 + temp->target->index;
		else
			temp->cost = ((size - temp->index ) + temp->target->index);
		temp = temp->next;
	}
}

