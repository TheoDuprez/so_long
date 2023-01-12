/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:36:49 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 14:21:34 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_bonus/so_long_bonus.h"

void	replace_char(t_slg *slg)
{
	if (slg->str[slg->x][slg->y] == 'P')
		slg->str[slg->x][slg->y] = '0';
	else if (slg->str[slg->x][slg->y] == 'C'
		|| (slg->str[slg->x][slg->y] == 'M' && slg->nb_c == 0))
	{
		if (slg->str[slg->x][slg->y] == 'C')
			slg->nb_c--;
		slg->str[slg->x][slg->y] = '0';
		if (slg->nb_c == 0)
		{
			slg->temp_x = slg->x;
			slg->temp_y = slg->y;
			exit_position(slg);
			what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
			slg->x = slg->temp_x;
			slg->y = slg->temp_y;
		}
		what_texture(slg->str[slg->x][slg->y], slg->y, slg->x, *slg);
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

int	ft_close(t_slg *slg)
{
	mlx_destroy_window(slg->mlx, slg->mlx_win);
	exit(1);
	return (1);
}
