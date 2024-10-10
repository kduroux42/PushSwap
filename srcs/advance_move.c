/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:36:07 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/10 15:56:29 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ss(t_node *A, t_node *B)
{
	/*
	if (!A || A->next || !B || !B->next)
		return ;
	*/
	swap(A, NULL);
	swap(B, NULL);
	ft_printf("ss\n");
}

void	rr(t_node **A, t_node **B)
{
	if (!*A || !(*A)->next || !*B || !(*B)->next)
		return ;
	rotate(A, NULL);
	rotate(B, NULL);
	ft_printf("rr\n");
}

void	rrr(t_node **A, t_node **B)
{
	if (!*A || !(*A)->next || !*B || !(*B)->next)
		return ;
	r_rotate(A, NULL);
	r_rotate(B, NULL);
	ft_printf("rrr\n");
}
