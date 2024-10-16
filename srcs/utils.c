/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:20:38 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/15 19:31:17 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
		/*
		*/
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	while (nptr[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(nptr) > 11)
			ft_printf("Error\n");
	}
	return (res * sign);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
