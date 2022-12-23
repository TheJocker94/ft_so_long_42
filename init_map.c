#include "so_long.h"

void	ft_error_map(char *error, t_mlx *init, char *map)
{
	free(map);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	ft_putstr_fd(error, 2);
	exit (0);
}

int	check_map(char *map, t_mlx *init)
{
	int	i;
	int f;
	int len;

	len = 0;
	f = 1;
	i = 0;
	while (map[i])
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			i++;
			len++;
		}
		if (f == 0)
		{
			init->check.line_2 = len;
			if (init->check.line_2 != init->check.line_1)
				ft_error_map("Error! Invalid map\n", init, map);
			len = 0;
		}
		else if (f == 1)
		{
			init->check.line_1 = len;
			f = 0;
			len = 0;
		}
		i++;
	}
	if ((init->check.exit > 1 || init->check.player > 1) || (init->check.exit == 0 || init->check.player == 0))
		ft_error_map("Error! Invalid map\n", init, map);
	return (1);	
}
t_tile	**ft_tilemap_alloc(char *map, t_mlx *init)
{
	t_tile	**tilemap;
	int		y;
	int		x;
	int		i;

	init->check.exit = 0;
	init->check.player = 0;
	y = 1;
	x = 0;
	i = 0;
	while (map[i])
	{
		if (y == 1)
			x++;
		if (map[i] == '\n' && map[i + 1] != '\0')
			y++;
		if (map[i] == 'C')
			init->collectible += 1;
		if (map[i] == 'E')
			init->check.exit += 1;
		if (map[i] == 'P')
			init->check.player += 1;
		i++;
	}
	init->x = x - 1;
	init->y = y;

	if (check_map(map, init) == 1)
		tilemap = (t_tile **)malloc(sizeof(t_tile *) * (y + 1));
	while (y--)
		tilemap[y] = (t_tile *)malloc(sizeof(t_tile) * (x));
	return (tilemap);
}

void	ft_init_map(t_mlx init, char *map)
{
	int	x;
	int	y;
	int	i;
	int	xbuff;
	int	ybuff;

	x = 0;
	y = 0;
	i = 0;
	xbuff = 20;
	ybuff = 20;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			ybuff += SIZE;
			y++;
			xbuff = 20;
			x = 0;
			i++;
		}
		if (!init.map[y])
			break ;
		init.map[y][x].position.x = xbuff;
		init.map[y][x].position.y = ybuff;
		init.map[y][x].type = map[i];
		init.map[y][x].ori_type = map[i];
		if (map[i] == 'P')
		{
			init.kingo.x = x;
			init.kingo.y = y;
		}
		if (x > 0)
			init.map[y][x].left = &init.map[y][x - 1];
		if (y > 0)
			init.map[y][x].up = &init.map[y - 1][x];
		if (x < init.x)
			init.map[y][x].right = &init.map[y][x + 1];
		if (y < init.y)
			init.map[y][x].down = &init.map[y + 1][x];
		xbuff += SIZE;
		x++;
		i++;
	}
	free(map);
}
