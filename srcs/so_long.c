/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:03:08 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/09 15:52:36 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

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
	mlx_hook(slg.mlx_win, 17, 0, ft_close, &slg);
	mlx_loop(slg.mlx);
}

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
		return (x * 64);
	return (y * 64);
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
	mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
	if (c == 'E' && slg.nb_c != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_c.xpm", &img_w, &img_h);
	else if (c == 'E' && slg.nb_c == 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/door_o.xpm", &img_w, &img_h);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(mlx, "xpm/ult_orb.xpm", &img_w, &img_h);
	else if (c == 'P' && slg.nb_c != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
}

int	ft_move(int keycode, t_slg *slg)
{
	move_player(keycode, slg);
	if (keycode == 53 || (slg->str[slg->x][slg->y] == 'E' && slg->nb_c == 0))
	{
		mlx_destroy_window(slg->mlx, slg->mlx_win);
		exit(1);
	}
	return (1);
}
