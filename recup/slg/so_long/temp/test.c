/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:36:48 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/21 14:43:09 by tduprez          ###   ########lyon.fr   */
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

void	what_texture(char c, int x, int y, t_slg slg, int i)
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
	// if (c != '1' && c != '0' && c != 'P')
	if (c != '1' && c != '0')
	{
		if (c == 'E')
			img = mlx_xpm_file_to_image(mlx, "xpm/door_o.xpm", &img_w, &img_h);
		if (c == 'C')
			img = mlx_xpm_file_to_image(mlx, "xpm/ult_orb.xpm", &img_w, &img_h);
		if (c == 'P' && i == 0)
			img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
		mlx_put_image_to_window(mlx, mlx_win, img, x * 200, y * 200);
	}
}

void	print_texture(char **str, t_slg slg, int i)
{
	int		x;
	int		y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x] && str[y][x] != '\n')
		{
			what_texture(str[y][x], x, y, slg, i);
			x++;
		}
		y++;
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

void move_player(int keycode, t_slg *slg)
{
	int			img_w;
	int			img_h;
	static int	i;
	static int	yes_no;
	void	*img;
	void	*mlx;
	void	*mlx_win;

	img = slg->mlx_img;
	mlx = slg->mlx;
	mlx_win = slg->mlx_win;
	printf("%d\n", yes_no);
	// if (yes_no == 0)
	// 	print_texture(slg->data.str, *slg);
	if (i == 0)
	{
		print_texture(slg->str, *slg, 1);
		player_position(slg);
	}
	i++;
	// printf("%d -> %d\n", slg->data.x, slg->data.y);
	img = mlx_xpm_file_to_image(mlx, "xpm/reyna.xpm", &img_w, &img_h);
	if (keycode == 2 && slg->str[slg->x][slg->y + 1] != '1')
	{
		print_texture(slg->str, *slg, 1);
		// if (i - 1 != 0)
			slg->y++;
		mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
		yes_no = 1;
	}
	else if (keycode == 1 && slg->str[slg->x + 1][slg->y] != '1')
	{
		print_texture(slg->str, *slg, 1);
		// if (i - 1 != 0)
			slg->x++;
		mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
		yes_no = 1;
	}
	else if (keycode == 0 && slg->str[slg->x][slg->y - 1] != '1')
	{
		print_texture(slg->str, *slg, 1);
		// if (i - 1 != 0)
			slg->y--;
		mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
		yes_no = 1;
	}
	else if (keycode == 13 && slg->str[slg->x - 1][slg->y] != '1')
	{
		print_texture(slg->str, *slg, 1);
		// if (i - 1 != 0)
			slg->x--;
		mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 200, slg->x * 200);
		yes_no = 1;
	}
	else
		yes_no = 0;
}

int	ft_move(int keycode, t_slg *slg)
{
	move_player(keycode, slg);
	if (keycode == 53)
		mlx_destroy_window(slg->mlx, slg->mlx_win);
	printf("%d\n", keycode);
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
	print_texture(str, slg, 0);
	slg.str = str;
	// mlx_key_hook(slg.data.mlx_win, ft_move, &slg);
	mlx_hook(slg.mlx_win, 2, 0, ft_move, &slg);
	mlx_loop(slg.mlx);
}
