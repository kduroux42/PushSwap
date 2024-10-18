/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:01 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 14:21:02 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

char	*av_to_str(char *av, char **stockage)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			count++;
		i++;
	}
	if (count == 0)
	{
		ft_printf("Error");
		exit(2);
	}
	*stockage = ft_strjoin(*stockage, av);
	return (*stockage);
}

char	*argv_to_str(char **av, char **stockage)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_printf("Error");
			free(*stockage);
			exit(2);
		}
		*stockage = ft_strjoin(*stockage, av[i]);
		*stockage = ft_strjoin(*stockage, " ");
		i++;
	}
	return (*stockage);
}

t_node	*create_stack(char *str)
{
	int		i;
	char	**res;
	t_node	*stack;
	t_node	*new_node;
	t_node	*head;

	i = 1;
	res = ft_split(str, ' ');
	stack = malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->nb = ft_atoi(res[0]);
	stack->next = NULL;
	head = stack;
	while (res[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->nb = ft_atoi(res[i++]);
		new_node->next = NULL;
		stack->next = new_node;
		stack = new_node;
	}
	return (free_split(res), head);
}
