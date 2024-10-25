/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:54:47 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/25 10:56:00 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	init_b(t_node **a, t_node **b)
{
	index_stack(a);
	index_stack(b);
	ft_setarsa(*a, *b);
	ft_find_cost(*a);
}

void	init_a(t_node **a, t_node **b)
{
	index_stack(a);
	index_stack(b);
	ft_setarsb(*b, *a);
	ft_find_cost(*b);
}
