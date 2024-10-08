/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:55:09 by kduroux           #+#    #+#             */
/*   Updated: 2024/09/30 13:55:10 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void swap(t_node *node) {

  int temp_nb;
  int temp_index;
  if (!node)
    return;
  temp_nb = node->nb;
  node->nb = node->next->nb;
  node->next->nb = temp_nb;
  temp_index = node->index;
  node->index = node->next->index;
  node->next->index = temp_index;
}

void push(t_node **stack_src, t_node **stack_dest) {
  t_node *temp;

  if (!stack_src)
    return;
  temp = (*stack_src)->next;
  (*stack_src)->next = *stack_dest;
  *stack_dest = *stack_src;
  *stack_src = temp;
}
