/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:42:37 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/06 16:13:57 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"), 6);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_puthex_ptr(unsigned long ptr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_puthex_ptr(ptr / 16);
	count += ft_putchar(hex[ptr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"), 5);
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_ptr((unsigned long)ptr);
	return (count);
}
