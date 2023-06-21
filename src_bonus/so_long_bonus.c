/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:34:57 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/21 11:44:39 by ocastell         ###   ########.fr       */
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
