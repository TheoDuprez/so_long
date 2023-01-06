# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:37:07 by tduprez           #+#    #+#              #
#    Updated: 2022/11/27 17:24:35 by tduprez          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_print_memory.c	ft_printf.c	ft_putchar.c	ft_putnbr_base.c	ft_putnbr_unsign.c	ft_putnbr.c	\
		ft_putmemory.c	ft_putstr.c

HEADER = ft_printf.h

OBJS = $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror

CC = gcc

RM = rm -f

AR = ar rcs

%.o:	%.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
