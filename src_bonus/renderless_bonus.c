/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderless_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:35:40 by ocastell          #+#    #+#             */
/*   Updated: 2023/01/17 18:35:43 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_map_render_logic_strano(t_mlx *init, t_tile **tile_map, int x, int y)
{
	if (tile_map[y][x].type == 'P')
	{
		ft_print_and_destroy(init, init->kingo_img.current_img, x, y);
		init->kingo.x = x;
		init->kingo.y = y;
	}
	else if (tile_map[y][x].type == 'F')
	{
		ft_print_and_destroy(init, init->enemy_img.current_img, x, y);
		init->enemy.x = x;
		init->enemy.y = y;
	}
	else if (tile_map[y][x].type == 'E')
	{
		ft_print_and_destroy(init, init->door_img.current_img, x, y);
		init->door.x = x;
		init->door.y = y;
	}
	else if (tile_map[y][x].type == 'C')
		ft_print_and_destroy(init, init->collect_img.current_img, x, y);
}

void	ft_map_render_strano(t_mlx *init, t_tile **tile_map, int x, int y)
{
	while (y--)
	{
		x = init->x;
		while (x--)
		{
			ft_map_render_logic_strano(init, tile_map, x, y);
		}
	}
}
