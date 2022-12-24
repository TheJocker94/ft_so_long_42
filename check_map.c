#include "so_long.h"

void	check_border(t_mlx *init)
{
	int		x;
	int		y;

	y = init->y;
	x = init->x;
	while (y--)
	{
		while (x--)
		{	
			if (init->map[0][x].type != '1')
				ft_error_border(init);
			if (init->map[y][0].type != '1')
				ft_error_border(init);
			if (init->map[y][init->x - 1].type != '1')
				ft_error_border(init);
			if (init->map[init->y - 1][x].type != '1')
				ft_error_border(init);
			if (init->map[y][x].type != '1' && init->map[y][x].type != 'E'
				&& init->map[y][x].type != 'C' && init->map[y][x].type != '0'
				&& init->map[y][x].type != 'P')
				ft_error_border(init);
		}
		x = init->x;
	}
	return ;
}

void	check_flood_logic_x(t_mlx *init, t_coord *p, t_coord *o, int mod)
{
	(*p).x = (*o).x + mod;
	(*p).y = (*o).y;
	check_flood(init, *p);
}

void	check_flood_logic_y(t_mlx *init, t_coord *p, t_coord *o, int mod)
{
	(*p).x = (*o).x;
	(*p).y = (*o).y + mod;
	check_flood(init, *p);
}

void	check_flood(t_mlx *init, t_coord o)
{
	t_coord	p;

	init->map[o.y][o.x].type = 'P';
	if (o.y > 0 && init->map[o.y - 1][o.x].type != '1'
		&& init->map[o.y - 1][o.x].type != 'P')
		check_flood_logic_y(init, &p, &o, -1);
	if (o.y < (init->y - 1) && init->map[o.y + 1][o.x].type != '1'
		&& init->map[o.y + 1][o.x].type != 'P')
		check_flood_logic_y(init, &p, &o, 1);
	if (o.x < (init->x - 1) && init->map[o.y][o.x + 1].type != '1'
		&& init->map[o.y][o.x + 1].type != 'P')
		check_flood_logic_x(init, &p, &o, 1);
	if (o.x > 0 && init->map[o.y][o.x - 1].type != '1'
		&& init->map[o.y][o.x - 1].type != 'P')
		check_flood_logic_x(init, &p, &o, -1);
}

/*void	check_flood(t_mlx *init, t_coord o)
{
	t_coord	p;

	init->map[o.y][o.x].type = 'P';
	if (o.y > 0 && init->map[o.y - 1][o.x].type != '1'
		&& init->map[o.y - 1][o.x].type != 'P')
	{
		p.x = o.x;
		p.y = o.y - 1;
		check_flood(init, p);
	}
	if (o.y < (init->y - 1) && init->map[o.y + 1][o.x].type != '1'
		&& init->map[o.y + 1][o.x].type != 'P')
	{
		p.x = o.x;
		p.y = o.y + 1;
		check_flood(init, p);
	}
	if (o.x < (init->x - 1) && init->map[o.y][o.x + 1].type != '1'
		&& init->map[o.y][o.x + 1].type != 'P')
	{
		p.x = o.x + 1;
		p.y = o.y;
		check_flood(init, p);
	}
	if (o.x > 0 && init->map[o.y][o.x - 1].type != '1'
		&& init->map[o.y][o.x - 1].type != 'P')
	{
		p.x = o.x - 1;
		p.y = o.y;
		check_flood(init, p);
	}
}*/
void	check_valid(t_mlx *init)
{
	int	x;
	int	y;

	x = init->x;
	y = init->y;
	check_flood(init, init->kingo);
	while (y--)
	{
		while (x--)
		{
			if (init->map[y][x].type != 'P' && init->map[y][x].type != '1'
				&& init->map[y][x].type != '0')
			{
				ft_putstr_fd("Error! Invalid map\n", 2);
				ft_close_error(init);
			}
		}
		x = init->x;
	}
	ft_reset_map(init);
}
