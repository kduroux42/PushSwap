/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:35:45 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/21 11:27:32 by kduroux          ###   ########.fr       */
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
	int				index;
	int				cost;
	int				count;
	struct s_stack	*target;
	struct s_stack	*next;
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

//advance_move_2
void	nrr(t_node **A, t_node **B, int n);
void	nrrr(t_node **A, t_node **B, int n);
void	nrotate(t_node **stack, char *str, int n);
void	nr_rotate(t_node **stack, char *str, int n);

//utils
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		check_long(const char *str, long res, long sign, int i);
void	free_split(char **str);
void	free_stack(t_node *stack);

//ft_printf_all
void	ft_printf_utils(t_node *stack);
void	ft_printf_stack(t_node *stack);
void	ft_printf_only_stack(t_node *stack);

//check_args
int		is_doublon(char *str);
int		is_valid(char *str);
int		ft_is_sorted(t_node *stack);
int		int_min_max(int nbi, long nbl);
int		ft_is_reverse_sorted(t_node *stack);

//create_stack
char	*argv_to_str(char **av, char **stockage);
char	*av_to_str(char *av, char **stockage);
t_node	*create_stack(char *str);

//sort_of_three
int		ft_find_index(t_node *a, int nbr);
int		ft_max(t_node *a);
int		ft_min(t_node *a);
void	ft_sort_three(t_node **stack);

//utils_for_sort
int		ft_lstsize_stack(t_node *stack);
void	index_stack(t_node **stack);
t_node	*ft_lstlast_stack(t_node *lst);

//utils_for_sort2
void	reverse_stack(t_node **stack, int i);
int		test(t_node *min, t_node **a, t_node **b);

//target
void    ft_setarsa(t_node *sta, t_node *stb);
void    ft_setarsb(t_node *sta, t_node *stb);

//push
t_node	*ft_min_cost(t_node *a);
t_node	*ft_max_ptr(t_node *a);
void	ft_push_to_a(t_node **b, t_node **a);
void	ft_push_to_b(t_node **a, t_node **b);
void	nnn(t_node *min, t_node **a, int n, int size);

//sort
void	sort_b(t_node	**stack);
void	ft_find_cost(t_node *a, int size_target);
void	sort(t_node **a);

#endif
