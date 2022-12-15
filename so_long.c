#include "minilibx-linux/mlx.h"

typedef struct struct_mlx
{
	void	*mlx;
	void	*mlx_win;
}mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	mlx	init;
	t_data img;

	init.mlx = mlx_init();
	init.mlx_win = mlx_new_window(init.mlx, 1920, 1080, "Hello Word");
	img.img = mlx_new_image(init.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(init.mlx, init.mlx_win, img.img, 0, 0);
	mlx_loop(init.mlx);
}

