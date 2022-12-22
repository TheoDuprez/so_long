#include "lib/check_map_error.h"
#include "lib/so_long.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	str = map_parser(argv[1]);
	if (!check_map_error(argv))
		return (0);
	so_long(str);
}
