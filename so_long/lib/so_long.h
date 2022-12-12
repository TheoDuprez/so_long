/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:50:50 by tduprez           #+#    #+#             */
/*   Updated: 2022/12/11 22:40:20 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// CHECK_MAP_ERROR

char	**map_parser(char *map);
int		check_map_wall(char **map, int nb_lines);
int		nb_lines(char	*map);
int		check_map_elements(char **map);
int		check_map_char(char **map);
int		ft_is_charset(char c, char *charset);
int		check_map_lines(char **map);
int		check_map_square(char **map, int nb_lines);

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
