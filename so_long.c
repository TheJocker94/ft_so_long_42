#include "so_long.h"

char	*ft_get_map(char *path_ber)
{
	int		fd;	
	char	*str;		
	char	*buff;

	str = ft_calloc(1, 1);
	fd = open(path_ber, O_RDONLY);
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
	return (str);
}
/*Chidere perchè bisogna per forza creare una variabile d'appogio per liberare l'ultimo blocco e cosa significa *init->map */
/*Gestire errori in caso in cui ci sia più di una E, più di unq P, la E non raggiungibile, C non raggiungibile,
(i nemici devono essere raggiungibili?), gestire formattazione della mappa (ad esempio se ci sono più /n alla fine e o in mezzo) VRisolto
se ci sono più spazi alla fine il programma va in core dump V Risolto*/

void	ft_freemap(t_mlx *init)
{
	t_tile	**tilemap;

	tilemap = init->map;
	while (*init->map != NULL)
	{
		free(*init->map);
		init->map++;
	}
	free(tilemap);
}

int	ft_close_error(t_mlx *init)
{
	//mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	ft_freemap(init);
	exit(0);
	return (0);
}

int	ft_close(t_mlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	ft_freemap(init);
	exit(0);
	return (0);
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

int	check_border(t_mlx *init)
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
		{
			ft_putstr_fd("Error! Invalid map\n", 2);
			ft_close_error(init);
		}
		if (init->map[y][0].type != '1')
		{
			ft_putstr_fd("Error! Invalid map\n", 2);
			ft_close_error(init);
		}
		if (init->map[y][init->x - 1].type != '1')
		{
			ft_putstr_fd("Error! Invalid map\n", 2);
			ft_close_error(init);
		}
		if (init->map[init->y - 1][x].type != '1')
		{
			ft_putstr_fd("Error! Invalid map\n", 2);
			ft_close_error(init);
		}
		if (init->map[y][x].type != '1' && init->map[y][x].type != 'E' && init->map[y][x].type != 'C' && init->map[y][x].type != '0' && init->map[y][x].type != 'P')
		{
			ft_putstr_fd("Error! Invalid map\n", 2);
			ft_close_error(init);
		}
	}
	x = init->x;
}
return (1);
}

/*void	check_flood(t_mlx *init)
{
	//char c;
	//t_coord p;
	//c = init->flood[init->pos_flood.y][init->pos_flood.x].type;
	init->flood[init->pos_flood.y][init->pos_flood.x].type = 'P';
	if (init->pos_flood.y > 0 && init->flood[init->pos_flood.y - 1][init->pos_flood.x].type != '1')
	{
		//p.x = init->pos_flood.x;
		init->pos_flood.y -= 1;
		check_flood(init);
	}
	if (init->pos_flood.y < (init->y - 1) && init->flood[init->pos_flood.y + 1][init->pos_flood.x].type != '1')
	{
		//p.x = init->pos_flood.x;
		init->pos_flood.y += 1;
		check_flood(init);
	}
	if (init->pos_flood.x < (init->x - 1) && init->flood[init->pos_flood.y][init->pos_flood.x + 1].type != '1')
	{
		init->pos_flood.x += 1;
		//p.y = init->pos_flood.y;
		check_flood(init);
	}
	if (init->pos_flood.x > 0 && init->flood[init->pos_flood.y][init->pos_flood.x - 1].type != '1')
	{
		init->pos_flood.x -= 1;
		//p.y = init->pos_flood.y;
		check_flood(init);
	}
}

void	check_valid(t_mlx *init)
{
	check_flood(init);
	int x = init->x;
	int y = init->y;
	while (y--)
	{
		while(x--)
		{
			if (init->flood[y][x].type == 'E' && init->flood[y][x].type == 'C')
			{
				ft_putstr_fd("Error! Invalid map\n", 2);
				//ft_freemap(init->flood);
				ft_close_error(init);
			}
		}
		x = init->x;
	}
}*/
int	main(void)
{
	t_mlx	init;
	char	*path_ber;
	char	*array_map;

	init.collectible = 0;
	init.moves = 0;
	init.mlx = mlx_init();
	path_ber = "test.ber";
	array_map = ft_get_map(path_ber);
	init.map = ft_tilemap_alloc(array_map, &init);
	ft_init_map(init, array_map);
	//init.flood = init.map;
	//init.pos_flood = init.kingo;
	if (check_border(&init) == 1)
		//check_valid(&init);
	init.win = mlx_new_window(init.mlx, (init.x * SIZE) + 40, (init.y * SIZE) + 40, "so_long");
	ft_map_render(&init, init.map, init.x, init.y);
	mlx_hook(init.win, 17, 0, ft_close, (void *)0);
	//ft_map_render(&init, init.map, init.x, init.y);
	ft_counter(&init);
	mlx_key_hook(init.win, key_input, &init);
	mlx_loop(init.mlx);
	return (0);
}
