/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:38 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/05 16:55:51 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_bonus/check_map_error_bonus.h"
#include "../lib_bonus/so_long_bonus.h"

int	is_finishable(t_error *error, char **str)
{
	int	x;
	int	y;

	error->map = str;
	player_position_finishable(error);
	x = error->x;
	y = error->y;
	// ft_diffusion(error, error->y, error->x);
	ft_diffusion(error, y, x);
	// ft_printer(error);
	if (!check_elements(error))
		return (1);
	return (0);
}

int	check_elements(t_error *error)
{
	int	x;
	int	y;

	x = 0;
	while (error->map[x])
	{
		y = 0;
		while (error->map[x][y] && error->map[x][y] != '\n')
		{
			if (error->map[x][y] == 'C' || error->map[x][y] == 'E')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_printer(t_error *error)
{
	int	x = 0;
	int	y = 0;
	while (error->map[y])
	{
		x = 0;
		while (error->map[y][x])
		{
			printf("%c", error->map[y][x]);
			x++;
		}
		y++;
	}
}

int	ft_diffusion(t_error *error, int y, int x)
{
	if (error->map[y][x] != '1' || error->map[y][x] != '*')
	{
		error->map[y][x] = '*';
		if (error->map[y][x + 1] != '1' && error->map[y][x + 1] != '*')
			ft_diffusion(error, y, x + 1);
		if (error->map[y][x - 1] != '1' && error->map[y][x - 1] != '*')
			ft_diffusion(error, y, x - 1);
		if (error->map[y + 1][x] != '1' && error->map[y + 1][x] != '*')
			ft_diffusion(error, y + 1, x);
		if (error->map[y - 1][x] != '1' && error->map[y - 1][x] != '*')
			ft_diffusion(error, y - 1, x);
	}
	return (1);
}

void	player_position_finishable(t_error *error)
{
	error->y = 0;
	error->x = 0;
	while (error->map[error->y])
	{
		error->x = 0;
		while (error->map[error->y][error->x])
		{
			if (error->map[error->y][error->x] == 'P')
				return ;
			error->x++;
		}
		error->y++;
	}
}
