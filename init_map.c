#include "so_long.h"

void	ft_tilemap_alloc_logic(t_mlx *init, char *map, int *x, int *y)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (*y == 1)
			*x = *x + 1;
		if (map[i] == '\n' && map[i + 1] != '\0')
			*y = *y + 1;
		if (map[i] == 'C')
			init->collectible += 1;
		if (map[i] == 'E')
			init->check.exit += 1;
		if (map[i] == 'P')
			init->check.player += 1;
		i++;
	}
}

t_tile	**ft_tilemap_alloc(char *map, t_mlx *init)
{
	t_tile	**tilemap;
	int		y;
	int		x;

	init->check.exit = 0;
	init->check.player = 0;
	y = 1;
	x = 0;
	ft_tilemap_alloc_logic(init, map, &x, &y);
	init->x = x - 1;
	init->y = y;
	init->check.col = init->collectible;
	if (check_map(map, init) == 1)
		tilemap = (t_tile **)malloc(sizeof(t_tile *) * (y + 1));
	while (y--)
		tilemap[y] = (t_tile *)malloc(sizeof(t_tile) * (x));
	return (tilemap);
}

void	ft_init_map_logic(t_mlx *init, int x, int y)
{
	if (init->map[y][x].type == 'P')
	{
		init->kingo.x = x;
		init->kingo.y = y;
	}
	if (x > 0)
		init->map[y][x].left = &init->map[y][x - 1];
	if (y > 0)
		init->map[y][x].up = &init->map[y - 1][x];
	if (x < init->x - 1)
		init->map[y][x].right = &init->map[y][x + 1];
	if (y < init->y - 1)
		init->map[y][x].down = &init->map[y + 1][x];
}

void	ft_init_map(t_mlx *init, char *map, int x, int y)
{
	int	xbuff;
	int	ybuff;

	xbuff = 20;
	ybuff = 20;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			ybuff += SIZE;
			y++;
			xbuff = 20;
			x = 0;
			map++;
		}
		if (!init->map[y])
			break ;
		init->map[y][x].position.x = xbuff;
		init->map[y][x].position.y = ybuff;
		init->map[y][x].type = *map;
		ft_init_map_logic(init, x, y);
		xbuff += SIZE;
		x++;
		map++;
	}
}
