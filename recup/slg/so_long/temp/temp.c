/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:36:48 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/21 12:59:41 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
// #include "../lib/so_long.h"

typedef struct s_slg
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**str;
	int		x;
	int		y;
	int		i;
}	t_slg;

int	convert_pxl(char **str, int n)
{
	int	x;
	int	y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x] && str[y][x] != '\n')
			x++;
		y++;
	}
	if (n == 0)
		return (x * 200);
	return (y * 200);
}

void	what_texture(char c, int x, int y, t_slg slg)
{
	int		img_w;
	int		img_h;
	void	*img;
	void	*mlx;
	void	*mlx_win;

	img = slg.mlx_img;
	mlx = slg.mlx;
	mlx_win = slg.mlx_win;
	if (c == '1')
		img = mlx_xpm_file_to_image(mlx, "xpm/wood.xpm", &img_w, &img_h);
	else
		img = mlx_xpm_file_to_image(mlx, "xpm/ground.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 200, y * 200);
	if (c == 'E' && slg.i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_c.xpm", &img_w, &img_h);
	else if (c == 'E' && slg.i == 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_o.xpm", &img_w, &img_h);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(mlx, "xpm/ult_orb.xpm", &img_w, &img_h);
	else if (c == 'P' && slg.i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 200, y * 200);
}

void	print_texture(char **str, t_slg slg)
{
	int		x;
	int		y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x] && str[y][x] != '\n')
		{
			what_texture(str[y][x], x, y, slg);
			x++;
		}
		y++;
	}
}

void	number_of_collectible(t_slg *slg)
{
	int	x;
	int	y;

	x = 0;
	slg->i = 0;
	while (slg->str[x])
	{
		y = 0;
		while (slg->str[x][y] && slg->str[x][y] != '\n')
		{
			if (slg->str[x][y] == 'C')
				slg->i++;
			y++;
		}
		x++;
	}
}

void	exit_position(t_slg *slg)
{
	slg->y = 0;
	slg->x = 0;
	while (slg->str[slg->x])
	{
		slg->y = 0;
		while (slg->str[slg->x][slg->y])
		{
			if (slg->str[slg->x][slg->y] == 'E')
				return ;
			slg->y++;
		}
		slg->x++;
	}
}

void	player_position(t_slg *slg)
{
	slg->y = 0;
	slg->x = 0;
	while (slg->str[slg->x])
	{
		slg->y = 0;
		while (slg->str[slg->x][slg->y])
		{
			if (slg->str[slg->x][slg->y] == 'P')
				return ;
			slg->y++;
		}
		slg->x++;
	}
}

void	replace_char(t_slg *slg)
{
	int	temp_x;
	int	temp_y;

	if (slg->str[slg->x][slg->y] == 'P')
		slg->str[slg->x][slg->y] = '0';
	else if (slg->str[slg->x][slg->y] == 'C')
	{
		slg->str[slg->x][slg->y] = '0';
		slg->i--;
		if (slg->i == 0)
		{
			temp_x = slg->x;
			temp_y = slg->y;
			exit_position(slg);
			what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
			slg->x = temp_x;
			slg->y = temp_y;
		}
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
	}
	// else if (slg->str[slg->x][slg->y] == 'E' && slg->i == 0)
	// // else if (slg->str[slg->x][slg->y] == 'E')
	// 	mlx_destroy_window(slg->mlx, slg->mlx_win);
}

void	move_player_direction(int keycode, t_slg *slg, int img_w, int img_h)
{
	void	*img;
	void	*mlx;
	void	*mlx_win;

	img = slg->mlx_img;
	mlx = slg->mlx;
	mlx_win = slg->mlx_win;
	replace_char(slg);
	if (slg->i != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	else
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna_ult.xpm", &img_w, &img_h);
	if (keycode == 2 && slg->str[slg->x][slg->y + 1] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y++, slg->x, *slg);
	else if (keycode == 1 && slg->str[slg->x + 1][slg->y] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x++, *slg);
	else if (keycode == 0 && slg->str[slg->x][slg->y - 1] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y--, slg->x, *slg);
	else if (keycode == 13 && slg->str[slg->x - 1][slg->y] != '1')
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x--, *slg);
	else
		return ;
	replace_char(slg);
	mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
}

void	move_player(int keycode, t_slg *slg)
{
	int			img_w;
	int			img_h;
	static int	i;

	if (i == 0)
	{
		number_of_collectible(slg);
		player_position(slg);
	}
	printf("%d\n", i);
	i++;
	move_player_direction(keycode, slg, img_w, img_h);
}

int	ft_move(int keycode, t_slg *slg)
{
	move_player(keycode, slg);
	if (keycode == 53 || (slg->str[slg->x][slg->y] == 'E' && slg->i == 0))
	{
		mlx_destroy_window(slg->mlx, slg->mlx_win);
		exit((int)slg->mlx);
	}
	return (0);
}

void	so_long(char **str)
{
	t_slg	slg;
	int		x;
	int		y;

	x = convert_pxl(str, 0);
	y = convert_pxl(str, 1);
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, x, y, "so_long");
	print_texture(str, slg);
	slg.str = str;
	mlx_hook(slg.mlx_win, 2, 0, ft_move, &slg);
	mlx_loop(slg.mlx);
}
