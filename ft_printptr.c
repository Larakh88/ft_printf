/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:53:03 by lel-khou          #+#    #+#             */
/*   Updated: 2022/01/05 19:14:58 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlength1(unsigned long long nb, int j)
{
	while (nb / 16 >= 1)
	{
		nb = nb / 16;
		j++;
	}
	return (j);
}

char	*ft_convertx1(unsigned long long nb)
{
	int		j;
	char	*str;

	j = 2;
	j = ft_hexlength1(nb, j);
	str = malloc(sizeof(char) * j);
	str[j - 1] = 0;
	while (nb / 16 > 0)
	{
		j--;
		if (nb % 16 >= 0 && nb % 16 <= 9)
			str[j - 1] = (nb % 16) + '0';
		else
			str[j - 1] = (nb % 16) + 87;
		nb = nb / 16;
	}
	j--;
	if (nb <= 9)
		str[j - 1] = nb + '0';
	else
		str[j - 1] = nb + 87;
	return (str);
}

int	ft_printptr(unsigned long long nb, unsigned int i)
{
	char	*str;

	i = i + 2;
	write(1, "0x", 2);
	if (nb >= 10 && nb <= 15)
	{
		i = ft_putchar(nb + 87, i);
		return (i);
	}
	str = ft_convertx1(nb);
	i = ft_putstr(str, i);
	free(str);
	return (i);
}
