/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:10 by lel-khou          #+#    #+#             */
/*   Updated: 2022/01/05 19:22:46 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int nb, unsigned int i)
{
	if (nb >= 10)
	{
		i = ft_putu(nb / 10, i);
		i = ft_putu(nb % 10, i);
	}
	else
		i = ft_putchar(nb + '0', i);
	return (i);
}

int	ft_type(const char *str, va_list ap, unsigned int i)
{
	char	*s;

	if (*str == 'c')
		i = ft_putchar(va_arg(ap, int), i);
	else if (*str == 'i' || *str == 'd')
		i = ft_putnbr(va_arg(ap, int), i);
	else if (*str == 'x')
		i = ft_printhex(va_arg(ap, int), i);
	else if (*str == 'X')
		i = ft_printhex_x(va_arg(ap, int), i);
	else if (*str == 'p')
		i = ft_printptr(va_arg(ap, long long), i);
	else if (*str == 'u')
		i = ft_putu(va_arg(ap, int), i);
	else if (*str == 's')
	{	
		s = va_arg(ap, char *);
		i = ft_putstr(s, i);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;

	va_start(ap, str);
	i = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				i = ft_putchar('%', i);
			else
				i = ft_type(str, ap, i);
		}
		else
			i = ft_putchar(*str, i);
		str++;
	}
	return (i);
}
