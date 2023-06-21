/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:28:27 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/21 11:30:25 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
