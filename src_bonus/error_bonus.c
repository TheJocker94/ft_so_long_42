/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:50 by ocastell          #+#    #+#             */
/*   Updated: 2023/01/17 18:32:54 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_map(char *error, char *map)
{
	free(map);
	ft_putstr_fd(error, 2);
}

int	ft_close_error(t_mlx *init)
{
	ft_freemap(init);
	ft_print_screen_error(init);
	return (0);
}

void	ft_error_border(t_mlx *init)
{
	ft_putstr_fd("Error! Invalid map\n", 2);
	free(init->path);
	ft_close_error(init);
}
