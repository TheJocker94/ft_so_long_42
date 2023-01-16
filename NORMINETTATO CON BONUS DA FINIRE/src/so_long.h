#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES

# include "../libft/libft.h"
# include "../mlx/mlx.h"

// STRUCTS
# define SIZE 64
# define BOR_X 40
# define BOR_Y 40
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

typedef struct struct_kingo_img_anim
{
	void	*current_img;
	int		anim_frames;
	void	*img_1;
	void	*img_2;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_8;
	void	*img_9;
	void	*img_10;
}	t_kingo_anim;

typedef struct struct_enemy_img_anim
{
	void	*current_img;
	int		anim_frames;
	void	*img_1;
	void	*img_2;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_8;
	void	*img_9;
	void	*img_10;
}	t_enemy_anim;

typedef struct struct_c_img_anim
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_c_img_anim;

typedef struct struct_d_img_anim
{
	void	*current_img;
	void	*img_1;
}	t_door_anim;

typedef struct s_coord
{
	int					x;
	int					y;

}						t_coord;

typedef struct s_check
{
	int					exit;
	int					player;
	int					enemy;
	int					line_1;
	int					line_2;
	int					col;

}						t_check;

typedef struct struct_tile
{
	t_coord				position;
	char				type;
	char				ori_type;
	struct struct_tile	*up;
	struct struct_tile	*down;
	struct struct_tile	*left;
	struct struct_tile	*right;
}						t_tile;

typedef struct struct_mlx
{
	void				*mlx;
	void				*win;
	t_tile				**map;
	void				*img;
	t_c_img_anim		collect_img;
	t_door_anim			door_img;
	t_kingo_anim		kingo_img;
	t_enemy_anim		enemy_img;
	t_check				check;
	t_coord				kingo;
	t_coord				door;
	t_coord				enemy;
	int					collectible;
	int					moves;
	int					x;
	int					y;
}						t_mlx;

void	ft_move_up(t_mlx *init, int x, int y);
void	ft_move_down(t_mlx *init, int x, int y);
void	ft_move_left(t_mlx *init, int x, int y);
void	ft_move_right(t_mlx *init, int x, int y);
void	ft_up(t_mlx *init, int x, int y);
void	ft_down(t_mlx *init, int x, int y);
void	ft_left(t_mlx *init, int x, int y);
void	ft_right(t_mlx *init, int x, int y);
void	ft_key_end_logic(t_mlx *init);
void	move_up_logic(t_mlx *init, int x, int y);
void	move_down_logic(t_mlx *init, int x, int y);
void	move_left_logic(t_mlx *init, int x, int y);
void	move_right_logic(t_mlx *init, int x, int y);
void	ft_init_img(t_mlx *init);
void	enemy_move_y(t_mlx *init, int x, int y);
void	enemy_move_x(t_mlx *init, int x, int y);
void	ft_enemy_mov(t_mlx *init);
int		animazioni(t_mlx *init);
void	ft_map_render(t_mlx *init, t_tile **tile_map, int x, int y);
void	ft_init_map(t_mlx *init, char *map, int x, int y);
t_tile	**ft_tilemap_alloc(char *map, t_mlx *init);
int		ft_close(t_mlx *init);
int		key_input(int keycode, t_mlx *init);
void	ft_counter(t_mlx *init);
void	ft_print_and_destroy(t_mlx *init, char *path, int x, int y);
void	ft_reset_map(t_mlx *init);
void	ft_restart(t_mlx *init);
void	ft_error_map(char *error, char *map);
void	ft_error_border(t_mlx *init);
int		ft_close_error(t_mlx *init);
void	ft_freemap(t_mlx *init);
void	check_border(t_mlx *init);
void	check_flood(t_mlx *init, t_coord origin);
void	check_valid(t_mlx *init);
int		check_map(char *map, t_mlx *init);
void	check_map_logic(t_mlx *init, char *map, int f, int len);

#endif
