/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:47:42 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 13:43:00 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/check_map_error.h"
#include "../ft_printf/ft_printf.h"

int	ft_strlen_pars(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
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
	char	*red;
	t_error	error;

	red = "\e[31m";
	str = map_parser(argv[1]);
	if (!check_map_lines(str) || !check_map_wall(str, nb_lines(argv[1]))
		|| !check_map_elements(str) || !check_map_char(str))
	{
		ft_printf("%sERROR\nBAD MAP FORMAT\n", red);
		return (ft_free(str, nb_lines(argv[1])), free(str), 0);
	}
	if (!is_finishable(&error, str, argv[1]))
	{
		ft_printf("%sERROR\nMAP NOT FINISHABLE\n", red);
		return (ft_free(str, nb_lines(argv[1])), free(str), 0);
	}
	return (ft_free(str, nb_lines(argv[1])), free(str), 1);
}
