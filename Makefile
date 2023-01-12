NAME =		so_long
NAME_BNS =	so_long_bonus
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -fsanitize=address -g3
MLXFLAGS =	-L mlx -lmlx -framework OpenGL -framework Appkit ft_printf/libftprintf.a
HEADERS =	lib/so_long.h	lib/check_map_error.h	lib_bonus/so_long_bonus.h	lib_bonus/check_map_error_bonus.h
OBJS =		$(SRCS:.c=.o)
OBJS_BNS =	$(SRCS_BNS:.c=.o)

SRCS =		srcs/so_long.c			srcs/so_long_utils1.c			srcs/so_long_utils2.c \
			srcs/check_map_error.c	srcs/check_map_error_utils.c	srcs/finishable.c \
			srcs/get_next_line.c	srcs/get_next_line_utils.c		main.c \

SRCS_BNS =	srcs_bonus/so_long_bonus.c			srcs_bonus/so_long_utils1_bonus.c			srcs_bonus/so_long_utils2_bonus.c \
			srcs_bonus/check_map_error_bonus.c	srcs_bonus/check_map_error_utils_bonus.c	srcs_bonus/finishable_bonus.c \
			srcs_bonus/get_next_line_bonus.c	srcs_bonus/get_next_line_utils_bonus.c		main_bonus.c \

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BNS)
$(NAME_BNS): $(OBJS_BNS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BNS) -o $(NAME_BNS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I

clean:
	rm -rf $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -rf $(NAME) $(NAME_BNS)

re: fclean $(NAME)

.PHONY: clean fclean re
