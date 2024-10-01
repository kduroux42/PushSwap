/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduroux <kduroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:55:02 by kduroux           #+#    #+#             */
/*   Updated: 2024/06/28 13:04:49 by kduroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_call_ft(va_list args, const char *format, int i);
int		ft_putnbr(int nbr);
int		ft_putnbru(int nbr);
int		ft_puthex_low(unsigned int nbr);
int		ft_puthex_up(unsigned int nbr);
int		ft_putptr(void *ptr);
int		ft_puthex_ptr(unsigned long ptr);
#endif
