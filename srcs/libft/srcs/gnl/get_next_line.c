/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:35:16 by kduroux           #+#    #+#             */
/*   Updated: 2024/07/01 15:30:26 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_read_file(int fd, char *stash)
{
	int			byte_read;
	char		*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		if (!stash)
			stash = ft_strdup("");
		if (!stash)
			return (free(buff), free(stash), NULL);
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(stash), free(buff), NULL);
		else if (byte_read == 0 && !*stash)
			return (free(stash), free(buff), NULL);
		buff[byte_read] = '\0';
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n') == 1)
			break ;
	}
	return (free(buff), stash);
}

char	*ft_get_nl(char *str)
{
	char	*stash;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (NULL);
	stash = ft_substr(str, i, ft_strlen(str) - i);
	if (!stash)
	{
		free(stash);
		stash = NULL;
	}
	str[i] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;

	str = ft_get_read_file(fd, stash);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_get_nl(str);
	return (str);
}
