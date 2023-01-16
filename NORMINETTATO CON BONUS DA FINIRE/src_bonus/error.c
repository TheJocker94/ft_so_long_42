#include "so_long_bonus.h"

void	ft_error_map(char *error, char *map)
{
	free(map);
	ft_putstr_fd(error, 2);
	exit (0);
}

int	ft_close_error(t_mlx *init)
{
	//mlx_destroy_display(init->mlx);
	//free(init->mlx);
	ft_freemap(init);
	exit(0);
	return (0);
}

void	ft_error_border(t_mlx *init)
{
	ft_putstr_fd("Error! Invalid map\n", 2);
	ft_close_error(init);
}
