/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:36:49 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/04 12:41:31 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	replace_char(t_slg *slg)
{
	if (slg->str[slg->x][slg->y] == 'P')
		slg->str[slg->x][slg->y] = '0';
	else if (slg->str[slg->x][slg->y] == 'C')
	{
		slg->str[slg->x][slg->y] = '0';
		slg->nb_c--;
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
