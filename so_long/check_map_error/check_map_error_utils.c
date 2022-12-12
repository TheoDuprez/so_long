/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:17:07 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/11 22:46:45 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// Checker si erreur en cas de map vide ou de map non envoyée
// Map rectengulaire en hauteur et largeur ?
// Script test maps error
// Chemin valide ?

int	ft_strlen_pars(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

// Nb line parse tout le fichier "map" et compte le nombre de lignes.
// Elle check si str[0] != '\n' pour ne pas compter une ligne en trop a
// la fin du fichier.
// Enfin, elle free str qui lui a permis de stocker les lignes

int	nb_lines(char	*map)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	if (str && str[0] != '\n')
		i++;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str && str[0] != '\n')
			i++;
	}
	close(fd);
	return (free(str), str = NULL, i);
}

// Map_parser va parser les lignes du fichier map, les stocker dans
// un tableau de tableau et return ce tableau,
// ce qui va servir par la suite a checker le format de la map

char	**map_parser(char *map)
{
	char	**res;
	int		fd;
	int		i;
	int		size;

	i = 0;
	res = malloc(sizeof(char *) * nb_lines(map) + 1);
	fd = open(map, O_RDONLY);
	res[i] = get_next_line(fd);
	while (res[i])
	{
		// printf("%s\n", res[i]);
		i++;
		res[i] = get_next_line(fd);
	}
	close(fd);
	return (res);
}

// Check_map_wall ca checker tout les murs exterieurs pour
// voir si il n'y a pas de trou dans la map.

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

int	check_map_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	collectible;
	int	start;

	i = -1;
	exit = 0;
	collectible = 0;
	start = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			else if (map[i][j] == 'C')
				collectible++;
		}
	}
	if (!(exit == 1 && start == 1 && collectible >= 1))
		return (0);
	return (1);
}

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

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

int	check_map_square(char **map, int nb_lines)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
		i++;
	if (nb_lines > i)
		return (0);
	return (1);
}
