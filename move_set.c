#include "so_long.h"

void	ft_move_up(t_mlx *init, int x, int y)
{
	if (init->map[y][x].up->type == '0')
	{
		init->map[y][x].up->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y - 1);
		init->kingo.y = y - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
	}
	else if (init->map[y][x].up->type == 'C')
	{
		init->map[y][x].up->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y - 1);
		ft_print_and_destroy(init, "personaggio/ReUmanoCollect.xpm", x, y - 1);
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y - 1);
		init->kingo.y = y - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		if (init->collectible == 0)
			ft_print_and_destroy(init, "door/door_open.xpm", init->door.x, init->door.y);
	}
	else if (init->map[y][x].up->type == 'E' && init->collectible == 0)
		ft_close(init);
	return ;
}

void	ft_move_down(t_mlx *init, int x, int y)
{
	if (init->map[y][x].down->type == '0')
	{
		init->map[y][x].down->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y + 1);
		init->kingo.y = y + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
	}	
	else if (init->map[y][x].down->type == 'C')
	{
		init->map[y][x].down->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y + 1);
		ft_print_and_destroy(init, "personaggio/ReUmanoCollect.xpm", x, y + 1);
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x, y + 1);
		init->kingo.y = y + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		if (init->collectible == 0)
			ft_print_and_destroy(init, "door/door_open.xpm", init->door.x, init->door.y);
	}
	else if (init->map[y][x].down->type == 'E' && init->collectible == 0)
		ft_close(init);
	return ;
}

void	ft_move_left(t_mlx *init, int x, int y)
{
	if (init->map[y][x].left->type == '0')
	{
		init->map[y][x].left->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x - 1, y);
		init->kingo.x = x - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
	}
	else if (init->map[y][x].left->type == 'C')
	{
		init->map[y][x].left->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x - 1, y);
		ft_print_and_destroy(init, "personaggio/ReUmanoCollect.xpm", x - 1, y);
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x - 1, y);
		init->kingo.x = x - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
		init->collectible -= 1;
		if (init->collectible == 0)
			ft_print_and_destroy(init, "door/door_open.xpm", init->door.x, init->door.y);
	}
	else if (init->map[y][x].left->type == 'E' && init->collectible == 0)
		ft_close(init);
	return ;
}

void	ft_move_right(t_mlx *init, int x, int y)
{
	if (init->map[y][x].right->type == '0')
	{
		init->map[y][x].right->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x + 1, y);
		init->kingo.x = x + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves += 1;
	}	
	else if (init->map[y][x].right->type == 'C')
	{
		init->map[y][x].right->type = 'P';
		ft_print_and_destroy(init, "personaggio/ReUmanoCollect.xpm", x + 1, y);
		ft_print_and_destroy(init, "personaggio/ReUmanoFloor.xpm", x + 1, y);
		init->kingo.x = x + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "wall_tiles/floor.xpm", x, y);
		init->moves = init->moves + 1;
		init->collectible -= 1;
		if (init->collectible == 0)
			ft_print_and_destroy(init, "door/door_open.xpm", init->door.x, init->door.y);
	}
	else if (init->map[y][x].right->type == 'E' && init->collectible == 0)
		ft_close(init);
	return ;
}

int	key_input(int keycode, t_mlx *init)
{
	int	x;
	int	y;

/*aggiungere animazione collexionabile ex=1*/
	x = init->kingo.x;
	y = init->kingo.y;
	if (keycode == 65307)
		ft_close(init);
	if (keycode == 65362 || keycode == 119)
		ft_move_up(init, x, y);
	else if (keycode == 65364 || keycode == 115)
		ft_move_down(init, x, y);
	else if (keycode == 65361 || keycode == 97)
		ft_move_left(init, x, y);
	else if (keycode == 65363 || keycode == 100)
		ft_move_right(init, x, y);
	//ft_map_render(init, init->map, init->x, init->y);
	init->img = mlx_new_image(init->mlx, (init->x * SIZE) + 40, 20);
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	mlx_destroy_image(init->mlx, init->img);
	ft_counter(init);
	return (0);
}
