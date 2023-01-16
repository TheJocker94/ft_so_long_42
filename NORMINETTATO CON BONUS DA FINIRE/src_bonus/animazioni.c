#include "so_long_bonus.h"

static void	collect_animation(t_c_img_anim *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	enemy_animation(t_enemy_anim *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
		img->current_img = img->img_1;
	else if (frame == img->anim_frames * 2)
		img->current_img = img->img_2;
	else if (frame == img->anim_frames * 3)
		img->current_img = img->img_5;
	else if (frame == img->anim_frames * 4)
		img->current_img = img->img_6;
	else if (frame == img->anim_frames * 5)
		img->current_img = img->img_7;
	else if (frame == img->anim_frames * 6)
		img->current_img = img->img_8;
	else if (frame == img->anim_frames * 7)
		img->current_img = img->img_9;
	else if (frame >= img->anim_frames * 8)
	{
		img->current_img = img->img_10;
		frame = 0;
	}
	frame += 1;
}

static void	kingo_animation(t_kingo_anim *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
		img->current_img = img->img_1;
	else if (frame == img->anim_frames * 2)
		img->current_img = img->img_2;
	else if (frame == img->anim_frames * 3)
		img->current_img = img->img_5;
	else if (frame == img->anim_frames * 4)
		img->current_img = img->img_6;
	else if (frame == img->anim_frames * 5)
		img->current_img = img->img_7;
	else if (frame == img->anim_frames * 6)
		img->current_img = img->img_8;
	else if (frame == img->anim_frames * 7)
		img->current_img = img->img_9;
	else if (frame >= img->anim_frames * 8)
	{
		img->current_img = img->img_10;
		frame = 0;
	}
	frame += 1;
}

static void	door_animation(t_mlx *init, t_door_anim *img)
{
	if (init->collectible == 0)
			img->current_img = img->img_1;
	return ;
}

int	animazioni(t_mlx *init)
{
	collect_animation(&init->collect_img);
	door_animation(init, &init->door_img);
	kingo_animation(&init->kingo_img);
	enemy_animation(&init->enemy_img);
	ft_map_render(init, init->map, init->x, init->y);
	return (1);
}
