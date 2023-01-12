/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:38 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 14:24:35 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/check_map_error.h"
#include "../lib/so_long.h"

int	is_finishable(t_error *error, char **str, char *path)
{
	error->map = str;
	player_position_finishable(error);
	ft_diffusion(error, error->y, error->x);
	if (!check_elements(error))
		return (ft_free(error->map, nb_lines(path)), 1);
	return (ft_free(error->map, nb_lines(path)), 0);
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

void	ft_free(char **str, int nb_lines)
{
	int	x;

	x = 0;
	while (x < nb_lines + 1)
	{
		free(str[x]);
		str[x] = NULL;
		x++;
	}
}
