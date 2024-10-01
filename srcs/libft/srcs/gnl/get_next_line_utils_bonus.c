/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:51:45 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/18 15:54:10 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char) c;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return (1);
		i++;
	}
	if (s[i] == cc)
		return (1);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*rest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	rest = malloc(1);
	if (!rest)
		return (NULL);
	if (ft_strlen(s) < start)
		return (rest);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (free(rest), NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (free(rest), ptr);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
