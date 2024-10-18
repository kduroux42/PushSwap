/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_of_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:37:19 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/14 10:37:20 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_max(t_node *a)
{
	int	i;

	i = a->nb;
	while (a)
	{
		if (a->nb > i)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

int	ft_min(t_node *a)
{
	int	i;

	i = a->nb;
	while (a)
	{
		if (a->nb < i)
			i = a->nb;
		a = a->next;
	}
	return (i);
}

int	ft_find_index(t_node *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nb != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	ft_sort_three(t_node **stack)
{
	if (ft_min(*stack) == (*stack)->nb)
	{
		r_rotate(stack, "rra");
		swap(*stack, "sa");
	}
	else if (ft_max(*stack) == (*stack)->nb)
	{
		rotate(stack, "ra");
		if (!ft_is_sorted(*stack))
			swap(*stack, "sa");
	}
	else
	{
		if (ft_find_index(*stack, ft_max(*stack)) == 1)
			r_rotate(stack, "rra");
		else
			swap(*stack, "sa");
	}
}
