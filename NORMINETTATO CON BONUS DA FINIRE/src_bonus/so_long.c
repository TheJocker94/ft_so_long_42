#include "so_long_bonus.h"

void	ft_fill_ori_type(t_mlx *init)
{
	int	x;
	int	y;

	x = init->x;
	y = init->y;
	while (y--)
	{
		while (x--)
		{
			init->map[y][x].ori_type = init->map[y][x].type;
		}
		x = init->x;
	}
}

char	*ft_get_map(char *path_ber)
{
	int		fd;	
	char	*str;		
	char	*buff;
	char	*path;

	path = ft_strjoin("map/", path_ber);
	str = ft_calloc(1, 1);
	fd = open(path, O_RDONLY);
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
	free(path);
	return (str);
}

void	start(t_mlx *init, int ac, char **av)
{
	char	*array_map;

	if (ac == 2)
	{
		ft_init_img(init);
		array_map = ft_get_map(av[1]);
		init->map = ft_tilemap_alloc(array_map, init);
		ft_init_map(init, array_map, 0, 0);
		free(array_map);
		ft_fill_ori_type(init);
		check_border(init);
		check_valid(init);
	}
	else
	{
		ft_putstr_fd("Error! Write 1 parameter\n", 2);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_mlx	init;

	start(&init, ac, av);
	init.mlx = mlx_init();
	init.win = mlx_new_window(init.mlx, (init.x * SIZE) + BOR_X,
			(init.y * SIZE) + BOR_Y, "so_long");
	ft_map_render(&init, init.map, init.x, init.y);
	mlx_hook(init.win, 17, 0, ft_close, &init);
	ft_counter(&init);
	mlx_key_hook(init.win, key_input, &init);
	mlx_loop_hook(init.mlx, animazioni, &init);
	mlx_loop(init.mlx);
	return (0);
}
