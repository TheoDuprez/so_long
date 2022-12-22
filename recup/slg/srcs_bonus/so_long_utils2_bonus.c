/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:36:49 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/22 13:19:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_bonus/so_long_bonus.h"

void	replace_char(t_slg *slg)
{
	int	temp_x;
	int	temp_y;
	int	y_n;

	y_n = 0;
	if (slg->str[slg->x][slg->y] == 'P')
		slg->str[slg->x][slg->y] = '0';
	else if (slg->str[slg->x][slg->y] == 'C' || (slg->str[slg->x][slg->y] == 'M' && slg->i == 0))
	{
		if (slg->str[slg->x][slg->y] == 'C')
		{
			slg->i--;
			y_n = 1;
		}
		slg->str[slg->x][slg->y] = '0';
		if (slg->i == 0 && y_n == 1)
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
