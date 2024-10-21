/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:35:47 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/21 11:54:07 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_push_to_b(t_node **a, t_node **b)
{
	int		size_of_a;
	int		size_of_b;
	//int		count;
	t_node	*min;

	size_of_a = ft_lstsize_stack(*a);
	while (size_of_a > 3)
	{
		size_of_b = ft_lstsize_stack(*b);
		index_stack(a);
		index_stack(b);
		ft_setarsa(*a, *b);
		ft_find_cost(*a);
		min = ft_min_cost(*a);
		//count = test(min, a, b);
		if (min->index <= size_of_a / 2)
		{
			nrotate(a, "ra", min->index);
			nnn(min, b, 1, size_of_b);
		}
		else if (min->index >= size_of_a / 2)
		{
			nr_rotate(a, "rra", size_of_a - min->index);
			nnn(min, b, 1, size_of_b);
		}
		push(a, b, "pb");
		size_of_a--;
	}
	reverse_stack(b, 1);
}

void	ft_push_to_a(t_node **b, t_node **a)
{
	int		size_of_a;
	int		size_of_b;
	//int		count;
	t_node	*min;

	size_of_b = ft_lstsize_stack(*b);
	while (size_of_b > 0)
	{
		size_of_a = ft_lstsize_stack(*a);
		index_stack(a);
		index_stack(b);
		ft_setarsb(*b, *a);
		ft_find_cost(*b);
		min = ft_min_cost(*b);
		//count = test(min, b, a);
		if (min->index <= size_of_b / 2)
		{
			nrotate(b, "rb", min->index);
			nnn(min, a, 0, size_of_a);
		}
		else if (min->index >= size_of_b / 2)
		{
			nr_rotate(b, "rrb", size_of_b - min->index);
			nnn(min, a, 0, size_of_a);
		}
		push(b, a, "pa");
		size_of_b--;
	}
	reverse_stack(a, 0);
}

void	nnn(t_node *min, t_node **a, int n, int size)
{
	if (n == 1)
	{
		if (min->target->index <= size / 2)
			nrotate(a, "rb", min->target->index);
		else
			nr_rotate(a, "rrb", (size - min->target->index));
	}
	else
	{
		if (min->target->index <= size / 2)
			nrotate(a, "ra", min->target->index);
		else
			nr_rotate(a, "rra", (size - min->target->index));
	}
}

t_node	*ft_min_cost(t_node *a)
{
	t_node	*temp;
	t_node	*minnode;

	temp = a->next;
	minnode = a;
	while (temp)
	{
		if (temp->cost < minnode->cost)
			minnode = temp;
		temp = temp->next;
	}
	return (minnode);
}

t_node	*ft_max_ptr(t_node *a)
{
	t_node	*temp;
	t_node	*maxnode;

	temp = a->next;
	maxnode = a;
	while (temp)
	{
		if (temp->nb > maxnode->nb)
			maxnode = temp;
		temp = temp->next;
	}
	return (maxnode);
}
