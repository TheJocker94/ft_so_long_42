#include "so_long_bonus.h"

/*Chidere perchè bisogna per forza creare una variabile d'appogio per liberare l'ultimo blocco e cosa significa *init->map */
/*Gestire errori in caso in cui ci sia più di una E, più di unq P, la E non raggiungibile, C non raggiungibile,
(i nemici devono essere raggiungibili?), gestire formattazione della mappa (ad esempio se ci sono più /n alla fine e o in mezzo) VRisolto
se ci sono più spazi alla fine il programma va in core dump V Risolto*/

void	ft_freemap(t_mlx *init)
{
	t_tile	**tilemap;
	int		y;

	tilemap = init->map;
	y = init->y;
	while (y--)
	{
		free(*init->map);
		init->map++;
	}
	free(tilemap);
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
