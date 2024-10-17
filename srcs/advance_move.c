/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:36:07 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/17 13:02:36 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	nrr(t_node **A, t_node **B, int n);
void	nrrr(t_node **A, t_node **B, int n);
void	nrotate(t_node **stack, char *str, int n);
void	nr_rotate(t_node **stack, char *str, int n);

void	nrr(t_node **A, t_node **B, int n)
{
	while (n > 0)
	{
		rr(A, B);
		n--;
	}
}
void	nrrr(t_node **A, t_node **B, int n)
{
	while (n > 0)
	{
		rrr(A, B);
		n--;
	}
}
void	nrotate(t_node **stack, char *str, int n)
{
	while (n > 0)
	{
		rotate(stack, str);
		n--;
	}
}
void	nr_rotate(t_node **stack, char *str, int n)
{
	while (n > 0)
	{
		r_rotate(stack, str);
		n--;
	}
}

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
