/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:13 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/10 13:38:39 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus/check_map_error_bonus.h"
#include "ft_printf/ft_printf.h"
#include "lib_bonus/so_long_bonus.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	**str;
	char	*r;

	r = "\e[31m";
	if (argc != 2)
		return (ft_printf("%sERROR\nTOO FEW OR TOO MANY ARGUMENTS\n", r), 1);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd == -1)
		return (ft_printf("%sERROR\nFILE DOES NOT EXIST\n", r), 1);
	i = ft_strlen(argv[1]);
	if (!(argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.'))
		return (ft_printf("%sERROR\nTHE MAP NEEDS AN EXTENSION .ber\n", r), 1);
	str = map_parser(argv[1]);
	if (!str)
		return (1);
	if (!check_map_error(argv))
		return (ft_free(str, nb_lines(argv[1])), free(str), 1);
	so_long(str);
	return (0);
}
