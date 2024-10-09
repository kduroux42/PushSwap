/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:35:45 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/02 16:17:11 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				index;

}	t_node;

//ft_swap
void	swap(t_node *node);
void	push(t_node **stack_src, t_node **stack_dest, char *str);
t_node *create_stack(int ac, char **av, char *str);
void	free_stack(t_node *stack);

//utils
void	ft_printf_stack(t_node *stack);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);

//ft_check
int		is_doublon(char *str);
int		is_valid(char *str);

//main
//int		is_doublon(char *str);
char	*argv_to_str(char **av, char **stockage);
void	free_split(char **str);

#endif
