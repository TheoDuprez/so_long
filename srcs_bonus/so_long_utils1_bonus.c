/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:11:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 10:20:57 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_bonus/so_long_bonus.h"
#include "../ft_printf/ft_printf.h"

void	move_player(int keycode, t_slg *slg)
{
	int			img_w;
	int			img_h;
	static int	i;
	static int	nb_move;

	img_w = 0;
	img_h = 0;
	if (i == 0)
	{
		number_of_collectible(slg);
		player_position(slg);
	}
	i++;
	if (ft_check_side(keycode, slg))
	{
		nb_move++;
		ft_printf("%s%d\n", "\e[32m", nb_move);
	}
	move_player_direction(keycode, slg, img_w, img_h);
}

void	number_of_collectible(t_slg *slg)
{
	int	x;
	int	y;

	x = 0;
	slg->nb_c = 0;
	while (slg->str[x])
	{
		y = 0;
		while (slg->str[x][y] && slg->str[x][y] != '\n')
		{
			if (slg->str[x][y] == 'C')
				slg->nb_c++;
			y++;
		}
		x++;
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

int	ft_check_side(int keycode, t_slg *slg)
{
	if (keycode == 2 && slg->str[slg->x][slg->y + 1] != '1')
		return (1);
	else if (keycode == 1 && slg->str[slg->x + 1][slg->y] != '1')
		return (1);
	else if (keycode == 0 && slg->str[slg->x][slg->y - 1] != '1')
		return (1);
	else if (keycode == 13 && slg->str[slg->x - 1][slg->y] != '1')
		return (1);
	return (0);
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
	if (slg->nb_c != 0)
		img = mlx_xpm_file_to_image(mlx, "xpm_b/reyna.xpm", &img_w, &img_h);
	else
		img = mlx_xpm_file_to_image(mlx, "xpm_b/reyna_ult.xpm", &img_w, &img_h);
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
	mlx_put_image_to_window(mlx, mlx_win, img, slg->y * 100, slg->x * 100);
}
