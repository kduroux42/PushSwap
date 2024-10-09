/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:39 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/02 16:35:01 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include <stdlib.h>

char	*av_to_str(char *av, char **stockage)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(av[i])
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
	int i;

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

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i]) {
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int ac, char **av)
{
	char 	*test;
	t_node	*stack;
	t_node	*stack_b;

	if (ac >= 2)
	{
		test = NULL;
		if (ac == 2)
			test = av_to_str(av[1], &test);
		else
			test = argv_to_str(av, &test);
		if (!is_valid(test) || is_doublon(test))
		{
			ft_printf("Error");
			return (free(test), 0);
		}
		stack = create_stack(ac, av,test);
		push( &stack, &stack_b, "pb");
		free(test);
		free_stack(stack);
		free(stack_b);
	}
	return (0);
}
