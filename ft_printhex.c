/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:53:03 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/20 14:32:02 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_convertx(int nb)
{
	int	x;
	int	j;
	char	*str;

	x = nb;
	j = 2;
	while (x / 16 >= 1)
	{
		x = x / 16;
		j++;
	}
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
	str[j - 1] = nb + '0';
	return (str);
}

int		ft_printhex(int nb, unsigned int i)
{
	char	*str;

	str = ft_convertx(nb);
	i = ft_putstr(str, i);
	free(str);
	return (i);
}
