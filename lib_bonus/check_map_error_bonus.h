/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:50:50 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 14:35:23 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_ERROR_BONUS_H
# define CHECK_MAP_ERROR_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* STRUCT */

typedef struct s_error
{
	int		y;
	int		x;
	char	**map;
}	t_error;

// CHECK_MAP_ERROR_BONUS.C //

int		ft_strlen_pars(char *s);
int		ft_is_charset(char c, char *charset);
char	**map_parser(char *map_path);
int		nb_lines(char *map_path);
int		check_map_error(char **argv);

// CHECK_MAP_ERROR_UTILS_BONUS.C //

int		check_map_wall(char **map, int nb_lines);
int		check_map_elements(char **map);
int		check_map_elements_2(char **map, int i, int j, char c);
int		check_map_char(char **map);
int		check_map_lines(char **map);

// FINISHABLE_BONUS.C //

int		is_finishable(t_error *error, char **str, char *path);
int		check_elements(t_error *error);
void	player_position_finishable(t_error *error);
int		ft_diffusion(t_error *error, int y, int x);
void	ft_free(char **str, int nb_lines);

// GET_NEXT_LINE //

int		ft_strchr(const char *s, int c);
char	*ft_reader(int fd, char *buf);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_after_cariage(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
