/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:57:18 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/17 13:31:33 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	sort_b(t_node **a)
{
	t_node	*b;

	b = NULL;
	push(a, &b, "pb");
	push(a, &b, "pb");
	if (!ft_is_reverse_sorted(b))
		swap(b, "sb");
	ft_push_to_b(a, &b);
	ft_sort_three(a);
	ft_push_to_a(&b, a);
	free_stack(b);
}

void	sort(t_node **a)
{
	if (!ft_is_sorted(*a))
	{
		if (ft_lstsize_stack(*a) == 2)
		{
			if (!ft_is_sorted(*a))
				swap(*a, "sa");
		}
		else if (ft_lstsize_stack(*a) == 3)
			ft_sort_three(a);
		else
			sort_b(a);
	}
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
			temp->cost = ((size - temp->index) + temp->target->index);
		temp = temp->next;
	}
}
