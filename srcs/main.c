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

char	*argv_to_str(char **av, char **stockage)
{
	int	i;

	i = 1;
	while(av[i])
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

int	is_valid(char *str)
{
	(void)str;
	return (1);
}


int	is_doublon(char *str)
{
	int	i;
	int	j;
	char **res;

	i = 0;
	res = ft_split(str, ' ');
	while (res[i])
	{
		j = 1 + i;
		while(res[j])
		{
			printf("%s vs %s\n", res[i], res[j]);
			if (res[i] == res[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char *test;

	if (ac >= 2)
	{
		test = NULL;
		test = argv_to_str(av, &test);
		printf("test : %s\n", test);
		printf("is doublon %d\n", is_doublon(test));
	}
	return (0);
}
