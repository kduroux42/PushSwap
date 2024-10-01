/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:47:41 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/06 16:13:27 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr(int nbr)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = (unsigned int)nbr;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		n = (unsigned int)(nbr * -1);
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbru(int nbr)
{
	int				count;
	unsigned int	nbru;

	count = 0;
	nbru = (unsigned int)nbr;
	if (nbru >= 10)
		count += ft_putnbru(nbru / 10);
	count += ft_putchar(nbru % 10 + '0');
	return (count);
}

int	ft_puthex_low(unsigned int nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthex_low(nbr / 16);
	count += ft_putchar(hex[nbr % 16]);
	return (count);
}

int	ft_puthex_up(unsigned int nbr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_puthex_up(nbr / 16);
	count += ft_putchar(hex[nbr % 16]);
	return (count);
}
