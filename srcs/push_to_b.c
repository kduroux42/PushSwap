/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:35:47 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/16 15:42:30 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_push_to_b(t_node **a, t_node **b)
{
	int		size_of_a;
	int		size_of_a_2;
	int		size_of_b;
	int		i;
	int		j;
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
		//ft_printf_utils(min);
		//ft_printf_stack(*a);
		if (min->cost == 0)
			push(a, b, "pb");
		else
		{
			if(min->index <= size_of_a_2 / 2 && min->target->index <= size_of_b / 2)
			{
				if(min->index > min->target->index)
				{
					i = min->target->index;
					while (i > 0)
					{
						rr(a, b);
						i--;
					}
					j = min->index - i;
					while(j > 0)
					{
						rotate(a, "ra");
						j--;
					}
					push(a, b, "pb");
				}
				else
				{
					i = min->index;
					while (i > 0)
					{
						rr(a, b);
						i--;
					}
					j = min->target->index - i;
					while(j > 0)
					{
						rotate(b, "rb");
						j--;
					}
					push(a, b, "pb");
				}
			}
			else if(min->index >= size_of_a_2 / 2 && min->target->index >= size_of_b / 2)
			{
				if(min->index > min->target->index)
				{
					i = min->target->index;
					while (i > 0)
					{
						rrr(a, b);
						i--;
					}
					j = min->index - i;
					while(j > 0)
					{
						r_rotate(a, "rra");
						j--;
					}
					push(a, b, "pb");
				}
				else
				{
					i = min->index;
					while (i > 0)
					{
						rrr(a, b);
						i--;
					}
					j = min->target->index - i;
					while(j > 0)
					{
						r_rotate(b, "rrb");
						j--;
					}
					push(a, b, "pb");
				}
			}
			else if(min->index <= size_of_a_2 / 2 && min->target->index >= size_of_b / 2)
			{
				if((size_of_a / 2 - min->index) < (size_of_b - min->target->index))
				{
					i = min->index;
					while (i > 0)
					{
						rotate(a, "ra");
						r_rotate(b, "rrb");
						i--;
					}
					j = min->target->index - i;
					while(j > 0)
					{
						r_rotate(b, "rrb");
						j--;
					}
					push(a, b, "pb");
				}
				else
				{
					i = min->target->index;
					while (i > 0)
					{
						rotate(b, "rb");
						r_rotate(a, "rra");
						i--;
					}
					j = min->index - i;
					while(j > 0)
					{
						r_rotate(a, "rra");
						j--;
					}
					push(a, b, "pb");
				}
			}
			else
			{
				if((size_of_a - min->index) > (size_of_b / 2 - min->target->index))
				{
					i = min->target->index;
					while (i > 0)
					{
						rotate(b, "rb ici");
						r_rotate(a, "rra ici");
						i--;
					}
					j = min->index - i;
					while(j > 0)
					{
						r_rotate(a, "rra la");
						j--;
					}
					push(a, b, "pb");
				}
				else
			{
					i = min->index;
					while (i > 0)
					{
						rotate(a, "ra");
						r_rotate(b, "rrb");
						i--;
					}
					j = min->target->index - i;
					while(j > 0)
					{
						r_rotate(b, "rrb");
						j--;
					}
					push(a, b, "pb");
				}
			}
			/*
	*/
		}
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
	ft_printf_stack(*b);
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
