/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:20:22 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 14:20:23 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"


int	is_valid(char *str)
{
	int		i;
	int		j;
	char	**res;

	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (!((res[i][j] >= '0' && res[i][j] <= '9')
				|| (res[i][j] == '-' && (res[i][j + 1] >= '0'
				&& res[i][j + 1] <= '9')
				&& !(res[i][j - 1] >= '0' && res[i][j - 1] <= '9'))))
				return (free_split(res), 0);
			j++;
		}
		i++;
	}
	free_split(res);
	return (1);
}

int	int_min_max(int nbi, long nbl)
{
	if (nbi != nbl)
		return (1);
	return (0);
}

int	is_doublon(char *str)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	res = ft_split(str, ' ');
	while (res[i])
	{
		if (int_min_max(ft_atoi(res[i]), ft_atol(res[i])))
			return (free_split(res), 1);
		j = 1 + i;
		while (res[j])
		{
			if (ft_atoi(res[i]) == ft_atoi(res[j])
				|| int_min_max(ft_atoi(res[j]), ft_atol(res[j])))
				return (free_split(res), 1);
			j++;
		}
		i++;
	}
	free_split(res);
	return (0);
}

int	ft_is_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (0);
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->nb > temp->nb)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	ft_is_reverse_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (0);
	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->nb < temp->nb)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

