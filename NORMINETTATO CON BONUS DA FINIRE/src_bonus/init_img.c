#include "so_long_bonus.h"

void	ft_init_collect(t_mlx *init)
{
	init->collectible = 0;
	init->moves = 0;
	init->collect_img.anim_frames = 10;
	init->collect_img.current_img = "../sprites/col/key.xpm";
	init->collect_img.img_0 = "../sprites/col/key_star.xpm";
	init->collect_img.img_1 = "../sprites/col/key.xpm";
	return ;
}

void	ft_init_exit(t_mlx *init)
{
	init->door_img.current_img = "../sprites/door/door_c.xpm";
	init->door_img.img_1 = "../sprites/door/door_o.xpm";
	return ;
}

void	ft_init_enemy(t_mlx *init)
{
	init->enemy_img.anim_frames = 5;
	init->enemy_img.current_img = "sprites/enemy/en_0.xpm";
	init->enemy_img.img_1 = "sprites/enemy/en_1.xpm";
	init->enemy_img.img_2 = "sprites/enemy/en_2.xpm";
	init->enemy_img.img_5 = "sprites/enemy/en_5.xpm";
	init->enemy_img.img_6 = "sprites/enemy/en_6.xpm";
	init->enemy_img.img_7 = "sprites/enemy/en_7.xpm";
	init->enemy_img.img_8 = "sprites/enemy/en_8.xpm";
	init->enemy_img.img_9 = "sprites/enemy/en_9.xpm";
	init->enemy_img.img_10 = "sprites/enemy/en_10.xpm";
	return ;
}

void	ft_init_kingo(t_mlx *init)
{
	init->collectible = 0;
	init->moves = 0;
	init->kingo_img.anim_frames = 5;
	init->kingo_img.current_img = "../sprites/kingo/kingo_0.xpm";
	init->kingo_img.img_1 = "../sprites/kingo/kingo_1.xpm";
	init->kingo_img.img_2 = "../sprites/kingo/kingo_2.xpm";
	init->kingo_img.img_5 = "../sprites/kingo/kingo_5.xpm";
	init->kingo_img.img_6 = "../sprites/kingo/kingo_6.xpm";
	init->kingo_img.img_7 = "../sprites/kingo/kingo_7.xpm";
	init->kingo_img.img_8 = "../sprites/kingo/kingo_8.xpm";
	init->kingo_img.img_9 = "../sprites/kingo/kingo_9.xpm";
	init->kingo_img.img_10 = "../sprites/kingo/kingo_10.xpm";
	return ;
}

void	ft_init_img(t_mlx *init)
{
	ft_init_collect(init);
	ft_init_exit(init);
	ft_init_kingo(init);
	ft_init_enemy(init);
	return ;
}
