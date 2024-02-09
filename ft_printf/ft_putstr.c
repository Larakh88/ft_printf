/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:10 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/20 12:46:54 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, unsigned int i)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (i + 6);
	}
	else
	{
		while (*str != 0)
		{
			write (1, str, 1);
			str++;
			i++;
		}
	}
	return (i);
}
