/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:13 by tduprez           #+#    #+#             */
/*   Updated: 2023/01/05 16:06:29 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus/check_map_error_bonus.h"
#include "ft_printf/ft_printf.h"
#include "lib_bonus/so_long_bonus.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	if (argc != 2)
		return (ft_printf("ERROR\nTOO FEW OR TOO MANY ARGUMENTS\n"), 0);
	while (argv[1][i])
		i++;
	if (!(argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.'))
		return (ft_printf("ERROR\nTHE MAP NEEDS AN EXTENSION '.ber'\n"), 0);
	str = map_parser(argv[1]);
	if (!str)
		return (1);
	if (!check_map_error(argv))
		return (0);
	so_long(str);
	return (0);
}
