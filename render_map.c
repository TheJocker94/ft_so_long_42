#include "so_long.h"

void	ft_print_and_destroy(t_mlx *init, char *path, int x, int y)
{
	int	size;

	size = SIZE;
	init->img = mlx_xpm_file_to_image(init->mlx, path, &size, &size);
	mlx_put_image_to_window(init->mlx, init->win, init->img, init->map[y][x].position.x, init->map[y][x].position.y);
	mlx_destroy_image(init->mlx, init->img);
}

void	ft_wall_render(t_mlx *init, int x, int y)
{
	if (x == 0 && y == 0)
		ft_print_and_destroy(init, "wall_tiles/corner_ul.xpm", x, y);
	else if (x == (init->x) - 1 && y == 0)
		ft_print_and_destroy(init, "wall_tiles/corner_ur.xpm", x, y);
	else if (x == 0 && (y + 1) == (init->y))
		ft_print_and_destroy(init, "wall_tiles/corner_ld.xpm", x, y);
	else if (x == (init->x) - 1 && (y + 1) == (init->y))
		ft_print_and_destroy(init, "wall_tiles/corner_rd.xpm", x, y);
	else if (y == 0)
		ft_print_and_destroy(init, "wall_tiles/wall_up.xpm", x, y);
	else if (x == 0)
		ft_print_and_destroy(init, "wall_tiles/wall_l.xpm", x, y);
	else if (x == (init->x) - 1)
		ft_print_and_destroy(init, "wall_tiles/wall_r.xpm", x, y);
	else if ((y + 1) == init->y)
		ft_print_and_destroy(init, "wall_tiles/wall_down.xpm", x, y);
	else
		ft_print_and_destroy(init, "wall_tiles/colonna.xpm", x, y);
	return ;
}

void	ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y)
{
	while (y--)
	{
		x = init->x;
		while (x--)
		{
			if (tile_map[y][x].type == '1')
				ft_wall_render(init, x, y);
			else if (tile_map[y][x].type == '0')
				ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
			else if (tile_map[y][x].type == 'P')
			{
				ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y);
				init->kingo.x = x;
				init->kingo.y = y;
			}
			else if (tile_map[y][x].type == 'E')
			{
				ft_print_and_destroy(init, "door/door_closed .xpm", x, y);
				init->door.x = x;
				init->door.y = y;
			}
			else if (tile_map[y][x].type == 'C')
				ft_print_and_destroy(init, "collect/key_star.xpm", x, y);
		}
	}
}
