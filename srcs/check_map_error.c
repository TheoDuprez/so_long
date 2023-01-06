/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:47:42 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/04 12:39:22 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/check_map_error.h"
#include "../ft_printf/ft_printf.h"

// Ft_strlen_pars va compter le nombre de char avant '\n' ou '\0'

int	ft_strlen_pars(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

// Ft_is_charset va checker si le char 'c' est dans la chaine charset

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

/*
Map_parser va parser les lignes du fichier map, les stocker dans
un tableau de tableau et return ce tableau,
ce qui va servir par la suite a checker le format de la map
*/

char	**map_parser(char *map_path)
{
	char	**res;
	int		fd;
	int		i;
	int		size;

	i = 0;
	size = nb_lines(map_path) + 1;
	res = malloc(sizeof(char *) * size);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (i < size)
	{
		res[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (res);
}

/*
Nb line parse tout le fichier "map" et compte le nombre de lignes.
Elle check si str[0] != '\n' pour ne pas compter une ligne en trop a
la fin du fichier.
Enfin, elle free str qui lui a permis de stocker les lignes
*/

int	nb_lines(char	*map_path)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_path, O_RDONLY);
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

int	check_map_error(char **argv)
{
	char	**str;

	str = map_parser(argv[1]);
	if (!check_map_lines(str))
		return (ft_printf("ERROR\nIN MAP : NOT EQUAL LINES\n"), 0);
	if (!check_map_wall(str, nb_lines(argv[1])))
		return (ft_printf("ERROR\nIN MAP : HOLE IN WALL\n"), 0);
	if (!check_map_elements(str))
		return (ft_printf("ERROR\nIN MAP : TOO FEW OR TOO MANY ELEMENTS\n"), 0);
	if (!check_map_char(str))
		return (ft_printf("ERROR\nIN MAP : UNKNOW CHAR\n"), 0);
	return (free(str), str = NULL, 1);
}
