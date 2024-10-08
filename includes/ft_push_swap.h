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

//main
int		is_doublon(char *str);
int		is_valid(char *str);
char	*argv_to_str(char **av, char **stockage);
void	free_split(char **str);

//try join
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(char *str);
#endif
