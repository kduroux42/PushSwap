/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:36:43 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/18 15:16:50 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_get_read_file(int fd, char *str);
char	*ft_one_line(char *str);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);

#endif
