#include "so_long.h"

char	*ft_get_map(char *path_ber)
{
	int		fd;	
	char	*str;		
	char	*buff;

	str = ft_calloc(1, 1);
	fd = open(path_ber, O_RDONLY);
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
		{
			close(fd);
			free(buff);
			break ;
		}
		str = ft_strjoinf(str, buff);
		free(buff);
	}
	return (str);
}

int	main(void)
{
	t_mlx	init;
	char	*path_ber;
	char	*array_map;

	init.collectible = 0;
	init.moves = 0;
	init.mlx = mlx_init();
	path_ber = "test.ber";
	array_map = ft_get_map(path_ber);
	init.map = ft_tilemap_alloc(array_map, &init);
	ft_init_map(&init, array_map);
	check_border(&init);
	check_valid(&init);
	init.win = mlx_new_window(init.mlx, (init.x * SIZE) + 40,
			(init.y * SIZE) + 40, "so_long");
	ft_map_render(&init, init.map, init.x, init.y);
	mlx_hook(init.win, 17, 0, ft_close, (void *)0);
	ft_counter(&init);
	mlx_key_hook(init.win, key_input, &init);
	mlx_loop(init.mlx);
	return (0);
}
