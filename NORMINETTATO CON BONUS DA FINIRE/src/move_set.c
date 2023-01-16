#include "so_long.h"

void	ft_move_up(t_mlx *init, int x, int y)
{
	if (init->map[y][x].up->type == '0')
		move_up_logic(init, x, y);
	else if (init->map[y][x].up->type == 'C')
	{
		move_up_logic(init, x, y);
		init->collectible -= 1;
	}
	else if (init->map[y][x].up->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].up->type == 'F')
		ft_close(init);
	if (init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_down(t_mlx *init, int x, int y)
{
	if (init->map[y][x].down->type == '0')
		move_down_logic(init, x, y);
	else if (init->map[y][x].down->type == 'C')
	{
		move_down_logic(init, x, y);
		init->collectible -= 1;
	}
	else if (init->map[y][x].down->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].down->type == 'F')
		ft_close(init);
	if (init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_left(t_mlx *init, int x, int y)
{
	if (init->map[y][x].left->type == '0')
		move_left_logic(init, x, y);
	else if (init->map[y][x].left->type == 'C')
	{
		move_left_logic(init, x, y);
		init->collectible -= 1;
	}
	else if (init->map[y][x].left->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].left->type == 'F')
		ft_close(init);
	if (init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

void	ft_move_right(t_mlx *init, int x, int y)
{
	if (init->map[y][x].right->type == '0')
		move_right_logic(init, x, y);
	else if (init->map[y][x].right->type == 'C')
	{
		move_right_logic(init, x, y);
		init->collectible -= 1;
	}
	else if (init->map[y][x].right->type == 'E' && init->collectible == 0)
		ft_close(init);
	else if (init->map[y][x].right->type == 'F')
		ft_close(init);
	if (init->check.enemy > 0)
		ft_enemy_mov(init);
	return ;
}

int	key_input(int keycode, t_mlx *init)
{
	int	x;
	int	y;
//aggiungere animazione collexionabile ex=1
	x = init->kingo.x;
	y = init->kingo.y;
	if (keycode == 65307)
		ft_close(init);
	if (keycode == 65362 || keycode == 119)
		ft_up(init, x, y);
	else if (keycode == 65364 || keycode == 115)
		ft_down(init, x, y);
	else if (keycode == 65361 || keycode == 97)
		ft_left(init, x, y);
	else if (keycode == 65363 || keycode == 100)
		ft_right(init, x, y);
	else if (keycode == 114)
		ft_restart(init);
	ft_key_end_logic(init);
	return (0);
}
