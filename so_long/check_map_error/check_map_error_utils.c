/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:17:07 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/11 13:47:39 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_error.h"

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
		i++;
		res[i] = get_next_line(fd);
	}
	i++;
	res[i] = NULL;
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
				return (1);
		}
		else
		{
			while (map[i][j++])
				if (j == 0 || j == (ft_strlen_pars(map[i]) - 1))
					if (map[i][j] != '1')
						return (1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	**str;
	char	path[] = "../map1.ber";
	int		i = 0;

	str = map_parser(path);
	// check_map_wall(str, nb_lines("../map1.ber"));
	if (check_map_wall(str, nb_lines(path)))
		printf("ERROR WALL\n");
	else
	{
		while (str[i])
		{
			printf("%s", str[i]);
			i++;
		}
	}
}
