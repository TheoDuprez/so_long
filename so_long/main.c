#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	str = map_parser(argv[1]);
	printf("%d\n", check_map_backtrack(str, argv[1], check_map_index_column(str, argv[1], 'P'), check_map_index_row(str, argv[1], 'P')));
	if (!check_map_error(argv))
		return (0);
	else
	{
		while (str[i])
		{
			printf("%s", str[i]);
			i++;
		}
	}
}

