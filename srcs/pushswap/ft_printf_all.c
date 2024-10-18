/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:08:44 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/18 17:09:15 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

void	ft_printf_stack(t_node *stack)
{
	ft_printf("------------------------------------------------------\n");
	while (stack)
	{
		ft_printf("nb : %d\n", stack->nb);
		ft_printf("index : %d\n", stack->index);
		ft_printf("target : %d\n", stack->target->nb);
		ft_printf("target->index : %d\n", stack->target->index);
		ft_printf("cost : %d\n", stack->cost);
		ft_printf("\n");
		stack = stack->next;
	}
	ft_printf("------------------------------------------------------\n");
}

void	ft_printf_only_stack(t_node *stack)
{
	ft_printf("------------------------------------------------------\n");
	while (stack)
	{
		ft_printf("nb : %d\n", stack->nb);
		stack = stack->next;
	}
	ft_printf("------------------------------------------------------\n");
}

void	ft_printf_utils(t_node *stack)
{
	ft_printf("------------------------------------------------------\n");
	ft_printf("nb : %d\n", stack->nb);
	ft_printf("index : %d\n", stack->index);
	ft_printf("target : %d\n", stack->target->nb);
	ft_printf("target->index : %d\n", stack->target->index);
	ft_printf("cost : %d\n", stack->cost);
	ft_printf("\n");
	ft_printf("------------------------------------------------------\n");
}
