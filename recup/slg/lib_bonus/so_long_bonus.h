/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:01:32 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/22 12:29:03 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include "../mlx/mlx.h"

/* Structure : */

typedef struct s_slg
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**str;
	int		x;
	int		x_e;
	int		y;
	int		y_e;
	int		i;
}	t_slg;

/* So_long.c : */

void	so_long(char **str);
int		convert_pxl(char **str, int n);
void	print_texture(char **str, t_slg slg);
void	what_texture(char c, int x, int y, t_slg slg);
int		ft_move(int keycode, t_slg *slg);

/* So_long_utils1.c */

void	move_player(int keycode, t_slg *slg);
void	number_of_collectible(t_slg *slg);
void	player_position(t_slg *slg);
int		ft_check_side(int keycode, t_slg *slg);
void	move_player_direction(int keycode, t_slg *slg, int img_w, int img_h);

/* So_long_utils2.c */

void	replace_char(t_slg *slg);
void	exit_position(t_slg *slg);

#endif
