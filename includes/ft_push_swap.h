/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:35:45 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 15:53:18 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				index;

}	t_node;

//move
void	swap(t_node *node, char *str);
void	push(t_node **stack_src, t_node **stack_dest, char *str);
void	rotate(t_node **stack, char *str);
void	r_rotate(t_node **stack, char *str);

//advance_move
void	ss(t_node *A, t_node *B);
void	rr(t_node **A, t_node **B);
void	rrr(t_node **A, t_node **B);

//utils
void	ft_printf_stack(t_node *stack);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	free_split(char **str);
void	free_stack(t_node *stack);

//check_args
int		is_doublon(char *str);
int		is_valid(char *str);

//create_stack
char	*argv_to_str(char **av, char **stockage);
char	*av_to_str(char *av, char **stockage);
t_node	*create_stack(char *str);
int		ft_is_sorted(t_node *stack);

#endif
