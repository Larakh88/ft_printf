/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:59:49 by lel-khou          #+#    #+#             */
/*   Updated: 2021/12/20 10:36:19 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_printhex(unsigned int nb, unsigned int i);
int	ft_putchar(char c, unsigned int i);
int	ft_putstr(char *str, unsigned int i);
int     ft_putnbr(int nb, unsigned int i);
int	ft_printhex_x(unsigned int nb, unsigned int i);

#endif
