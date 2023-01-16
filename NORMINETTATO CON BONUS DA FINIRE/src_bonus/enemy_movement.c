#include "so_long_bonus.h"

void	enemy_move_x(t_mlx *init, int x, int y)
{
	if (init->map[y][x].left->type == '0' && x > init->kingo.x)
	{
		init->map[y][x].left->type = 'F';
		ft_print_and_destroy(init, init->enemy_img.current_img, x - 1, y);
		init->enemy.x = init->kingo.x + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	}
	else if (init->map[y][x].right->type == '0' && x < init->kingo.x)
	{
		init->map[y][x].right->type = 'F';
		ft_print_and_destroy(init, init->enemy_img.current_img, x + 1, y);
		init->enemy.x = init->kingo.x - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	}
}

void	enemy_move_y(t_mlx *init, int x, int y)
{
	if (init->map[y][x].up->type == '0' && y > init->kingo.y)
	{
		init->map[y][x].up->type = 'F';
		ft_print_and_destroy(init, init->enemy_img.current_img, x, y - 1);
		init->enemy.y = init->kingo.y + 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	}
	else if (init->map[y][x].down->type == '0' && y < init->kingo.y)
	{
		init->map[y][x].down->type = 'F';
		ft_print_and_destroy(init, init->enemy_img.current_img, x, y + 1);
		init->enemy.y = init->kingo.y - 1;
		init->map[y][x].type = '0';
		ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	}
}

void	ft_enemy_mov(t_mlx *init)
{
	int	x;
	int	y;

	x = init->enemy.x;
	y = init->enemy.y;
	if (x != init->kingo.x)
	{
		enemy_move_x(init, x, y);
	}
	else if (y != init->kingo.y)
	{
		enemy_move_y(init, x, y);
	}
	if (init->enemy.x == init->kingo.x && init->enemy.y == init->kingo.y)
		ft_close(init);
}
