#include "so_long_bonus.h"

void	ft_up(t_mlx *init, int x, int y)
{
	ft_move_up(init, x, y);
	write(1, "UP\n", 3);
}

void	ft_down(t_mlx *init, int x, int y)
{
	ft_move_down(init, x, y);
	write(1, "DOWN\n", 5);
}

void	ft_left(t_mlx *init, int x, int y)
{
	ft_move_left(init, x, y);
	write(1, "LEFT\n", 5);
}

void	ft_right(t_mlx *init, int x, int y)
{
	ft_move_right(init, x, y);
	write(1, "RIGHT\n", 6);
}

void	ft_key_end_logic(t_mlx *init)
{
	init->img = mlx_new_image(init->mlx, (init->x * SIZE) + 40, 20);
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	mlx_destroy_image(init->mlx, init->img);
	ft_counter(init);
}
