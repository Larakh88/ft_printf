/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:10 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/12 20:24:20 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c, unsigned int i)
{
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putstr(char *str, unsigned int i)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (i + 6);
	}
	else
		while (*str != 0)
		{
			write (1, str, 1);
			str++;
			i++;
		}
	return (i);
}

int	ft_putnbr(int nb, unsigned int i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (i + 11);
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		i = ft_putchar('-', i);
	}
	if (nb >= 10)
	{
		i = ft_putnbr(nb / 10, i);
		i = ft_putnbr(nb % 10, i);
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
	else if (*str == '%')
		i = ft_putchar('%', i);
	else if (*str == 's')
	{	
		s = va_arg(ap, char *);
		i = ft_putstr(s, i);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	unsigned int	i;

	va_start(ap, str);
	i = 0; 
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			i = ft_type(str, ap, i);
			va_arg(ap, int);	
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			i++;
		}
	}
	return (i);
}

int main()
{
	int i = 100;
	int *a = &i;
	printf("%d\n", printf(" %p\n", a));
	//printf("%d\n", ft_printf(" %u\n", 0));
}

