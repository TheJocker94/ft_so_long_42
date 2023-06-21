/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:43:49 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/21 11:54:48 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_print_404(t_mlx *init)
{
	ft_putstr_fd("Error! Invalid map\n", 2);
	free(init->path);
	ft_close_error(init);
}

void	ft_error_stamp(t_mlx *init, char *map)
{
	free(init->path);
	ft_error_map("Error! Invalid map\n", map);
	ft_print_screen_error(init);
}
