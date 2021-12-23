# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lel-khou <lel-khou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:15:34 by lel-khou          #+#    #+#              #
#    Updated: 2021/12/15 12:15:37 by lel-khou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

HEADER = ft_printf.h

RM = rm -f

CFILES = ft_printf.c ft_printhex.c ft_strlen.c ft_putchar.c ft_putstr.c

OBJS = $(CFILES:.c=.o)

all :$(NAME)

$(NAME) : $(OBJS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
