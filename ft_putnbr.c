/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:10 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/20 12:46:54 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
