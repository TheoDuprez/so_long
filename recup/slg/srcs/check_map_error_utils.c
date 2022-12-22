/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:17:07 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/21 12:56:57 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/check_map_error.h"

// Checker si erreur en cas de map vide ou de map non envoyée
// Script test maps error
// Chemin valide ?

/*
Check_map_wall ca checker tout les murs exterieurs pour
voir si il n'y a pas de trou dans la map.
*/

int	check_map_wall(char **map, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == (nb_lines - 1))
		{
			while (map[i][j] == '1')
				j++;
			if (j != ft_strlen_pars(map[i]))
				return (0);
		}
		else
		{
			while (map[i][j++])
				if (j == 0 || j == (ft_strlen_pars(map[i]) - 1))
					if (map[i][j] != '1')
						return (0);
		}
		i++;
	}
	return (1);
}

/*
Check_map_elements va checker le nombre de collectible,
de sorties et de positions de départ
*/

int	check_map_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	collectible;
	int	start;

	i = 0;
	exit = 0;
	collectible = 0;
	start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			exit += check_map_elements_2(map, i, j, 'E');
			start += check_map_elements_2(map, i, j, 'P');
			collectible += check_map_elements_2(map, i, j, 'C');
			j++;
		}
		i++;
	}
	if (!(exit == 1 && start == 1 && collectible >= 1))
		return (0);
	return (1);
}

int	check_map_elements_2(char **map, int i, int j, char c)
{
	int	res;

	res = 0;
	if (map[i][j] == c)
		res++;
	return (res);
}

// Check_map_char va checker si il y a un autre char que "CPE10\n"

int	check_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_is_charset(map[i][j], "CPE10\n"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Check_map_lines va checker si les lignes sont d'une longeur differente

int	check_map_lines(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != k && i > 0)
			return (0);
		k = j;
		i++;
	}
	return (1);
}
