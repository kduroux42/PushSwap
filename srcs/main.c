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

char	*av_to_str(char *av, char **stockage)
{
	if (!av)
		exit(2);
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
			printf("Error");
			return (free(test), 0);
		}
		stack = create_stack(ac, av,test);
		ft_printf_stack(stack);
		//swap(stack);
		push(&stack, &stack_b);
		push(&stack, &stack_b);
		push(&stack, &stack_b);
		printf("\n");
		ft_printf_stack(stack);
		printf("\n");
		ft_printf_stack(stack_b);
		free_stack(stack);
	}
	return (0);
}
