/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:53:03 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/20 14:32:02 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlength_x(unsigned int nb, int j)
{
	while (nb / 16 >= 1)
	{
		nb = nb / 16;
		j++;
	}
	return (j);
}

char	*ft_convertx_x(unsigned int nb)
{
	int	j;
	char	*str;

	j = 2;
	j = ft_hexlength_x(nb, j);
	str = malloc(sizeof(char) * j);
	str[j - 1] = 0;
	while (nb / 16 > 0)
	{
		j--;
		if (nb % 16 >= 0 && nb % 16 <= 9)
			str[j - 1] = (nb % 16) + '0';
		else
			str[j - 1] = (nb % 16) + 55;
		nb = nb / 16;	
	}
	j--;	
	if (nb <= 9)
		str[j - 1] = nb + '0';
	else
		str[j-1] = nb + 55;
	return (str);
}

int	ft_printhex_x(unsigned int nb, unsigned int i)
{
	char	*str;

	if (nb >= 10 && nb <= 15)
	{
		i = ft_putchar(nb + 55, i);
		return(i);
	}
	str = ft_convertx_x(nb);
	i = ft_putstr(str, i);
	free(str);
	return (i);
}
