/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:34:57 by ocastell          #+#    #+#             */
/*   Updated: 2023/01/17 18:35:00 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fill_ori_type(t_mlx *init)
{
	int	x;
	int	y;

	x = init->x;
	y = init->y;
	while (y--)
	{
		while (x--)
		{
			init->map[y][x].ori_type = init->map[y][x].type;
		}
		x = init->x;
	}
}

char	*ft_get_map(char *path_ber)
{
	int		fd;
	char	*str;
	char	*buff;
	char	*path;

	path = ft_strjoin("map/", path_ber);
	str = ft_calloc(1, 1);
	fd = open(path, O_RDONLY);
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
	free(path);
	return (str);
}

void	ft_close_menu(t_mlx *init, int flg)
{
	int	i;

	i = 0;
	while (init->menu.map[i])
	{
		free(init->menu.map[i]);
		init->menu.map[i++] = NULL;
	}
	free(init->menu.map);
	mlx_destroy_image(init->menu.mlx, init->menu.menu);
	mlx_destroy_image(init->menu.mlx, init->menu.win);
	mlx_destroy_image(init->menu.mlx, init->menu.game_over);
	mlx_destroy_image(init->menu.mlx, init->menu.jump_mic);
	mlx_destroy_window(init->menu.mlx, init->menu.wind);
	mlx_destroy_display(init->menu.mlx);
	free(init->menu.mlx);
	if (flg)
		exit(0);
	else
		ft_funziona(init);
}

void	ft_print_menu(t_mlx *init)
{
	mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
		init->menu.menu, 0, 0);
	mlx_string_put(init->menu.mlx, init->menu.wind, 100,
		220, 0xffffff, "Maps : ");
	mlx_string_put(init->menu.mlx, init->menu.wind, 145,
		220, 0xffffff, init->menu.map[init->menu.i]);
}

int	ft_menu_key(int keycode, t_mlx *init)
{
	if (keycode == 65362 || keycode == 119)
	{
		init->menu.i--;
		if (init->menu.i < 0)
			init->menu.i = init->menu.i_max;
		ft_print_menu(init);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		init->menu.i++;
		if (init->menu.i > init->menu.i_max)
			init->menu.i = 0;
		ft_print_menu(init);
	}
	else if (keycode == 65293)
	{
		init->enter = 1;
		init->path = ft_strdup(init->menu.map[init->menu.i]);
		ft_close_menu(init, 0);
	}
	else if (keycode == 65307)
		ft_close_menu(init, 1);
	return (0);
}

int	ft_splash(int key, t_mlx *init)
{
	(void)key;
	mlx_destroy_image(init->menu.mlx, init->menu.win);
	mlx_destroy_image(init->menu.mlx, init->menu.game_over);
	mlx_destroy_image(init->menu.mlx, init->menu.jump_mic);
	mlx_destroy_window(init->menu.mlx, init->menu.wind);
	mlx_destroy_display(init->menu.mlx);
	free(init->menu.mlx);
	exit(0);
	return (0);
}

void	ft_print_if(t_mlx *init, int p)
{
	if (p == 1)
	{
		mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
			init->menu.win, 0, 0);
	}
	else if (p == 2)
	{
		mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
			init->menu.game_over, 0, 0);
	}
	else if (p == 3)
	{
		mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
			init->menu.jump_mic, 0, 0);
	}
}

void	ft_print_screen(t_mlx *init, int p)
{
	int		x;
	int		y;

	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	free(init->path);
	ft_freemap(init);
	init->menu.mlx = mlx_init();
	init->menu.wind = mlx_new_window(init->menu.mlx, 320,
			252, "so_long");
	init->menu.win = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/win.xpm", &x, &y);
	init->menu.game_over = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/gameover.xpm", &x, &y);
	init->menu.jump_mic = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/wrong_map.xpm", &x, &y);
	ft_print_if(init, p);
	mlx_hook(init->menu.wind, 2, 1L << 0, ft_splash, init);
	mlx_loop(init->menu.mlx);
}

int	ft_splashia(int key, t_mlx *init)
{
	(void)key;
	mlx_destroy_image(init->menu.mlx, init->menu.jump_mic);
	mlx_destroy_window(init->menu.mlx, init->menu.wind);
	mlx_destroy_display(init->menu.mlx);
	free(init->menu.mlx);
	exit(0);
	return (0);
}

void	ft_print_screen_error(t_mlx *init)
{
	int		x;
	int		y;

	init->menu.mlx = mlx_init();
	init->menu.wind = mlx_new_window(init->menu.mlx, 320,
			252, "so_long");
	init->menu.jump_mic = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/wrong_map.xpm", &x, &y);
	mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
		init->menu.jump_mic, 0, 0);
	mlx_hook(init->menu.wind, 2, 1L << 0, ft_splashia, init);
	mlx_loop(init->menu.mlx);
}

void	ft_init_menu_utils(t_mlx *init)
{
	int		fd;
	char	*str;
	char	*buff;
	int		i;

	i = 0;
	fd = open("txt/map.txt", O_RDONLY);
	str = ft_calloc(1, 1);
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
	init->menu.map = ft_split(str, '\n');
	while (init->menu.map[i])
		i++;
	init->menu.i_max = i - 1;
	free(str);
}

void	ft_init_menu(t_mlx *init)
{
	int		x;
	int		y;

	init->menu.flg = 1;
	init->menu.i = 0;
	init->menu.mlx = mlx_init();
	init->menu.wind = mlx_new_window(init->menu.mlx, 320,
			252, "so_long");
	init->menu.menu = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/menu.xpm", &x, &y);
	init->menu.win = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/win.xpm", &x, &y);
	init->menu.game_over = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/gameover.xpm", &x, &y);
	init->menu.jump_mic = mlx_xpm_file_to_image(init->menu.mlx,
			"sprites/menu/wrong_map.xpm", &x, &y);
	ft_init_menu_utils(init);
	return ;
}

void	ft_menu(t_mlx *init)
{
	init->enter = 0;
	if (init->menu.flg)
	{
		printf("\r  menu 1st");
		init->menu.flg = 0;
		init->menu.i = 0;
		mlx_put_image_to_window(init->menu.mlx, init->menu.wind,
			init->menu.menu, 0, 0);
		mlx_string_put(init->menu.mlx, init->menu.wind, 100, 220,
			0xffffff, "Maps : ");
		mlx_string_put(init->menu.mlx, init->menu.wind, 145, 220,
			0xffffff, init->menu.map[init->menu.i]);
	}
	mlx_hook(init->menu.wind, 2, 1L << 0, ft_menu_key, init);
	if (init->enter)
		return ;
	mlx_loop(init->menu.mlx);
}

void	ft_funziona(t_mlx *init)
{
	char	*array_map;

	ft_init_img(init);
	array_map = ft_get_map(init->path);
	init->map = ft_tilemap_alloc(array_map, init);
	ft_init_map(init, array_map, 0, 0);
	free(array_map);
	ft_fill_ori_type(init);
	check_border(init);
	check_valid(init);
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, (init->x * SIZE) + BOR_X,
			(init->y * SIZE) + BOR_Y, "so_long");
	ft_map_render(init, init->map, init->x, init->y);
	mlx_hook(init->win, 17, 0, ft_close, init);
	ft_counter(init);
	mlx_hook(init->win, 2, 1L << 0, key_input, init);
	mlx_loop_hook(init->mlx, animazioni, init);
	mlx_loop(init->mlx);
}

void	start(t_mlx *init)
{
	ft_init_menu(init);
	ft_menu(init);
}

int	main(void)
{
	t_mlx	init;

	start(&init);
	return (0);
}
