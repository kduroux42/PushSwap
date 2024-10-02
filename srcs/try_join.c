/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:03:29 by kduroux           #+#    #+#             */
/*   Updated: 2024/10/02 16:05:26 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

size_t	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (int)((ft_strlen2(s1) + ft_strlen2(s2) + 1)));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}
