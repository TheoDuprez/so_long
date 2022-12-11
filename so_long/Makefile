NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c

OBJS = $(SRCS:.c=.o)

HEADER = minilibx-linux/mlx.h



%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

