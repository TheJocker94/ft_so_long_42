/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:40:59 by ocastell          #+#    #+#             */
/*   Updated: 2023/01/17 18:41:02 by ocastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_check				check;
	t_coord				kingo;
	t_coord				door;
	int					collectible;
	int					moves;
	int					x;
	int					y;
}						t_mlx;

void	ft_map_render_strano(t_mlx *init, t_tile **tile_map, int x, int y);
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
