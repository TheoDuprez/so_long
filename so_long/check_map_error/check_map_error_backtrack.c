/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error_backtrack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:07:53 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/14 16:43:07 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	check_map_index_row(char **map, char *map_path, char c)
{
	int	len_row;
	int	len_column;
	int	i;
	int	j;

	len_row = ft_strlen_pars(map[0]);
	len_column = nb_lines(map_path);
	i = 0;
	while (len_column > i)
	{
		j = 0;
		while (len_row > j)
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_index_column(char **map, char *map_path, char c)
{
	int	len_row;
	int	len_column;
	int	i;
	int	j;

	len_row = ft_strlen_pars(map[0]);
	len_column = nb_lines(map_path);
	i = 0;
	while (len_column > i)
	{
		j = 0;
		while (len_row > j)
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_coordinates(char **map, char *map_path, int i, int j)
{
	int	len_row;
	int	len_column;

	len_row = ft_strlen_pars(map[0]);
	len_column = nb_lines(map_path);
	if (i < 0 || i > len_column - 1);
		return (1);
	if (j < 0 || j > len_row - 1)
		return (1);
	return (0);
}

int	check_map_backtrack(char **map, char *map_path, int i, int j)
{
	if (!check_map_coordinates(map, map_path, i, j))
		return (0);
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
		j++;
	else if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
		j--;
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
		i++;
	else if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
		i--;
	return (check_map_backtrack(map, map_path, i, j));
}
