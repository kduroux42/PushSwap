/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:39 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 15:46:58 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	*test;
	t_node	*stack;

	test = NULL;
	if (ac >= 2)
	{
		if (ac == 2)
			test = av_to_str(av[1], &test);
		else
			test = argv_to_str(av, &test);
		if (!is_valid(test) || is_doublon(test))
		{
			ft_printf("Error\n");
			return (free(test), 0);
		}
		stack = create_stack(test);
		free(test);
		if (!ft_is_sorted(stack))
			sort(&stack);
		ft_is_sorted(stack);
		free_stack(stack);
	}
	return (0);
}
