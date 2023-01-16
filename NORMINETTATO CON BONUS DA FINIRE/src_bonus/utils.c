#include "so_long_bonus.h"

void	ft_restart(t_mlx *init)
{
	ft_reset_map(init);
	init->moves = 0;
	init->collectible = init->check.col;
	ft_map_render(init, init->map, init->x, init->y);
}

void	ft_reset_map(t_mlx *init)
{
	int	x;
	int	y;

	x = init->x;
	y = init->y;
	while (y--)
	{
		while (x--)
		{
			init->map[y][x].type = init->map[y][x].ori_type;
		}
		x = init->x;
	}
}

void	ft_counter(t_mlx *init)
{
	char	*move;
	char	*col;

	move = ft_itoa(init->moves);
	col = ft_itoa(init->collectible);
	mlx_string_put(init->mlx, init->win, 20, 15, 0xffffffff, "Moves :");
	mlx_string_put(init->mlx, init->win, 80, 15, 0xffffffff, move);
	mlx_string_put(init->mlx, init->win, 150, 15, 0xffffffff, "Collectible :");
	mlx_string_put(init->mlx, init->win, 250, 15, 0xffffffff, col);
	free(move);
	free(col);
}

int	check_map(char *map, t_mlx *init)
{
	int	i;
	int	f;
	int	len;

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
		check_map_logic(init, map, f, len);
		if (map[i] == '\n' && map[i + 1] == '\0')
			ft_error_map("Error! Invalid map\n", map);
		i++;
	}
	if ((init->check.exit > 1 || init->check.player > 1)
		|| (init->check.exit == 0 || init->check.player == 0
			|| init->check.col == 0))
		ft_error_map("Error! Invalid map\n", map);
	return (1);
}

void	check_map_logic(t_mlx *init, char *map, int f, int len)
{
	if (f == 0)
	{
		init->check.line_2 = len;
		if (init->check.line_2 != init->check.line_1)
			ft_error_map("Error! Invalid map\n", map);
		len = 0;
	}
	else if (f == 1)
	{
		init->check.line_1 = len;
		f = 0;
		len = 0;
	}
}
