/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:05:51 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/28 13:03:54 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_call_ft(va_list args, const char *format, int i)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format [i] == '%')
		return (ft_putchar(format[i]));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_putnbru(va_arg(args, int)));
	else if (format[i] == 'x')
		return (ft_puthex_low(va_arg(args, int)));
	else if (format[i] == 'X')
		return (ft_puthex_up(va_arg(args, int)));
	else if (format[i] == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (ft_putchar(format[i]));
}

int	ft_check_opt(char format)
{
	int		i;
	char	*opt;

	i = 0;
	opt = "cspdiuxX%";
	while (opt[i])
	{
		if (opt[i] == format)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			if (ft_check_opt(format[i + 1]) == 0)
				count += ft_putchar(format[i]);
			i++;
			if (!format)
				return (count);
			count += ft_call_ft(args, format, i++);
		}
	}
	va_end(args);
	return (count);
}
