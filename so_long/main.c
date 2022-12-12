#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	char	**str;
	int		i = 0;

	str = map_parser(argv[1]);
	if (!check_map_lines(str))
	{
		printf("ERROR IN MAP : NOT EQUAL LINES");
		return (1);
	}
	if (!check_map_wall(str, nb_lines(argv[1])))
	{
		printf("ERROR IN MAP : HOLE IN WALL\n");
		return (1);
	}
	if (!check_map_elements(str))
	{
		printf("ERROR IN MAP : TOO FEW OR TOO MANY ELEMENTS\n");
		return (1);
	}
	if (!check_map_char(str))
	{
		printf("ERROR IN MAP : UNKNOW CHAR\n");
		return (1);
	}
	if (!check_map_square(str, nb_lines(argv[1])))
	{
		printf("ERROR IN MAP : MAP IS NOT SQUARE");
	}
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
}

