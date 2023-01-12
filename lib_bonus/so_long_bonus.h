/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:01:32 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 14:33:44 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

/* STRUCT */

typedef struct s_slg
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	**str;
	int		x;
	int		y;
	int		temp_x;
	int		temp_y;
	int		nb_c;
}	t_slg;

// SO_LONG_BONUS.C //

void	so_long(char **str);
int		convert_pxl(char **str, int n);
void	print_texture(char **str, t_slg slg);
void	what_texture(char c, int x, int y, t_slg slg);
int		ft_move(int keycode, t_slg *slg);

// SO_LONG_UTILS1_BONUS.C //

void	move_player(int keycode, t_slg *slg);
void	number_of_collectible(t_slg *slg);
void	player_position(t_slg *slg);
int		ft_check_side(int keycode, t_slg *slg);
void	move_player_direction(int keycode, t_slg *slg, int img_w, int img_h);

// SO_LONG_UTILS2_BONUS.C //

void	replace_char(t_slg *slg);
void	exit_position(t_slg *slg);
int		ft_close(t_slg *slg);

#endif
