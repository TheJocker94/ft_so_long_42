/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:32 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/21 11:44:56 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
