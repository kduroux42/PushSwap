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

int	main(int ac, char **av)
{
	char	*test;
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
		stack = create_stack(test);
		rotate(&stack, "ra");
		rotate(&stack, "ra");
		rotate(&stack, "ra");
		swap(stack, "sa");
		ft_printf_stack(stack);
		push(&stack, &stack_b, "pb");
		push(&stack_b, &stack, "pa");
		ft_printf_stack(stack);
		free(test);
		free_stack(stack);
	}
	return (0);
}
