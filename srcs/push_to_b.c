/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:35:47 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/17 13:31:17 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_push_to_b(t_node **a, t_node **b)
{
	int		size_of_a;
	int		size_of_a_2;
	int		size_of_b;
	t_node	*min;

	size_of_a = ft_lstsize_stack(*a);
	while (size_of_a > 3)
	{
		size_of_a_2 = ft_lstsize_stack(*a);
		size_of_b = ft_lstsize_stack(*b);
		index_stack(a);
		index_stack(b);
		ft_setarsa(*a, *b);
		ft_setarsb(*b, *a);
		ft_find_cost(*a);
		min = ft_min_cost(*a);
		if (min->cost > 0)
		{
			if(min->index <= size_of_a_2 / 2 && min->target->index <= size_of_b / 2)
			{
				if(min->index > min->target->index)
				{
					nrotate(a, "ra", min->index - min->target->index);
					nrr(a, b, min->target->index);
				}
				else
				{
					nrotate(b, "rb", min->target->index - min->index);
					nrr(a, b,  min->index);
				}
			}
			else if(min->index >= size_of_a_2 / 2 && min->target->index >= size_of_b / 2)
			{
				if(min->index > min->target->index)
				{
					nr_rotate(a, "rra", min->index - (size_of_b - min->target->index));
					nrrr(a, b, min->target->index);
				}
				else
				{
					nr_rotate(b, "rrb", min->target->index - (size_of_a_2 - min->index));
					nrrr(a, b,  size_of_a_2 - min->index);
				}
			}
			else if(min->index <= size_of_a_2 / 2 && min->target->index >= size_of_b / 2)
			{
				if((size_of_a / 2 - min->index) < (size_of_b - min->target->index))
				{
					nrotate(a, "ra",  min->index);
					nr_rotate(b, "rrb", min->target->index);
				}
				else
				{
					nrotate(b, "rb", min->target->index);
					nr_rotate(a, "rra", min->index);
				}
			}
			else
			{
				if((size_of_a - min->index) > (size_of_b / 2 - min->target->index))
				{
					nrotate(b, "rb", min->target->index);
					nr_rotate(a, "rra", min->index);
				}
				else
				{
					nrotate(a, "ra", min->index);
					nr_rotate(b, "rrb", min->target->index);
				}
			}
		}
		push(a, b, "pb");
		size_of_a--;
	}
	/*
	while(!ft_is_reverse_sorted(*b))
	{
		if (ft_max_ptr(*a)->index == size_of_b)
			r_rotate(b, "rrb");
		else
			rotate(b, "rb");
	}
*/
}

void	ft_push_to_b_2(t_node **a, t_node **b)
{
	int		size_of_a;
	int		size_of_a_2;
	int		size_of_b;
	t_node	*min;

	size_of_a = ft_lstsize_stack(*a);
	while (size_of_a > 3)
	{
		size_of_a_2 = ft_lstsize_stack(*a);
		size_of_b = ft_lstsize_stack(*b);
		index_stack(a);
		index_stack(b);
		//ft_setarsa(*a, *b);
		ft_setarsb(*a, *b);
		ft_find_cost(*a);
		min = ft_min_cost(*a);
		ft_printf_utils(min);
		if (min->index <= size_of_a_2 / 2)
		{
			nrotate(a, "ra", min->index);
			if (min->target->index <= size_of_b / 2)
				nrotate(b, "rb", min->target->index);
			else
				nr_rotate(b, "rrb", size_of_b / 2 - min->target->index);
		}
		else if (min->index >= size_of_a_2 / 2)
		{
			nr_rotate(a, "rra", size_of_a_2 / 2 - min->index);
			if (min->target->index <= size_of_b / 2)
				nrotate(b, "rb", min->target->index);
			else
				nr_rotate(b, "rrb", size_of_b / 2 - min->target->index);
		}
		push(a, b, "pb");
		size_of_a--;
	}
	/*
	while(!ft_is_sorted(*b))
	{
		if (ft_max_ptr(*a)->index == size_of_b)
			r_rotate(b, "rrb");
		else
			rotate(b, "rb");
	}
	*/
}

t_node	*ft_min_cost(t_node *a)
{
	t_node	*temp;
	t_node	*minNode;

	temp = a->next;
	minNode = a;
	while (temp)
	{
		if (temp->cost < minNode->cost)
			minNode = temp;
		temp = temp->next;
	}
	return (minNode);
}

t_node	*ft_max_ptr(t_node *a)
{
	t_node	*temp;
	t_node	*maxNode;

	temp = a->next;
	maxNode = a;
	while (temp)
	{
		if (temp->nb > maxNode->nb)
			maxNode = temp;
		temp = temp->next;
	}
	return (maxNode);
}

void	ft_push_to_a(t_node **b, t_node **a)
{
	int		size_of_a;
	int		size_of_b_2;
	int		size_of_b;
	int		count_for_r;
	t_node	*min;

	size_of_b = ft_lstsize_stack(*b);
	while (size_of_b > 0)
	{
		size_of_b_2 = ft_lstsize_stack(*b);
		size_of_a = ft_lstsize_stack(*a);
		count_for_r = 0;
		index_stack(a);
		index_stack(b);
		ft_setarsa(*a, *b);
		ft_setarsb(*b, *a);
		ft_find_cost(*b);
		min = ft_min_cost(*b);
		if (min->index <= size_of_b_2 / 2)
		{
			nrotate(b, "rb", min->index - count_for_r);
			if (min->target->index <= size_of_a / 2)
				nrotate(a, "ra", min->target->index);
			else
				nr_rotate(a, "rra", size_of_a - min->target->index);
		}
		else if (min->index >= size_of_b_2 / 2)
		{
			nr_rotate(b, "rrb", size_of_b_2 / 2 - min->index);
			if (min->target->index <= size_of_a / 2)
				nrotate(a, "ra", min->target->index);
			else
				nr_rotate(a, "rra", size_of_a / 2 - min->target->index);
		}
		push(b, a, "pa");
		size_of_b--;
	}

	/*
	while(!ft_is_sorted(*a))
	{
		if (ft_max_ptr(*a)->index == size_of_a)
			r_rotate(a, "rra");
		else
			rotate(a, "ra");
	}
*/
}
