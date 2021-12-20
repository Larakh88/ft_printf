/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
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
char	*ft_printx(int nb)
{
	int	x;
	int	j;
	char	*str;

	x = nb;
	j = 0;
	while (x / 16 > 16)
	{
		x = x / 16;
		j++;
	}
	str = malloc(sizeof(char) * (j + 2));
	j = 0;
	while (nb / 16 > 0)
	{
		if (nb % 16 >= 0 && nb % 16 <= 9)
			str[j++] = nb % 16;
		else
			str[j++] = (nb % 16) + 87;
		nb = nb / 16;	
	}	
	str[j] = nb;
	return (str);
}

int		ft_print(int nb, unsigned int i)
{
	int		l;
	char	*str;

	str = ft_printx(nb);
	l = strlen(str);
	while (l >= 0)
	{
		write(1, str[l], 1);
		l--;
		i++;
	}
	return (i);
}

int main()
{
    ft_print(2000, 1);
}
