/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:18:05 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/15 19:19:56 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static t_node    *ft_helptarsa(t_node *stb)
{
    t_node    *best_tar;

    best_tar = NULL;
    while (stb)
    {
        if (!best_tar || stb->nb > best_tar->nb)
            best_tar = stb;
        stb = stb->next;
    }
    return (best_tar);
}

void    ft_setarsa(t_node *sta, t_node *stb)
{
    t_node    *temp_a;
    t_node    *temp_b;
    t_node    *best_tar;

    temp_a = sta;
    while (temp_a)
    {
        temp_b = stb;
        best_tar = NULL;
        while (temp_b)
        {
            if (temp_b->nb < temp_a->nb
                && (!best_tar || temp_b->nb > best_tar->nb))
                best_tar = temp_b;
            temp_b = temp_b->next;
        }
        if (!best_tar)
            best_tar = ft_helptarsa(stb);
        temp_a->target = best_tar;
        temp_a = temp_a->next;
    }
}

static t_node    *ft_helptarsb(t_node *sta, t_node *best_tar)
{
    t_node    *temp_a;

    temp_a = sta;
    while (temp_a)
    {
        if (!best_tar || temp_a->nb < best_tar->nb)
            best_tar = temp_a;
        temp_a = temp_a->next;
    }
    return (best_tar);
}

void    ft_setarsb(t_node *stb, t_node *sta)
{
    t_node    *temp_b;
    t_node    *temp_a;
    t_node    *best_tar;

    temp_b = stb;
    while (temp_b)
    {
        temp_a = sta;
        best_tar = NULL;
        while (temp_a)
        {
            if (temp_a->nb > temp_b->nb
                && (!best_tar || temp_a->nb < best_tar->nb))
                best_tar = temp_a;
            temp_a = temp_a->next;
        }
        if (!best_tar)
            best_tar = ft_helptarsb(sta, best_tar);
        temp_b->target = best_tar;
        temp_b = temp_b->next;
    }
}
