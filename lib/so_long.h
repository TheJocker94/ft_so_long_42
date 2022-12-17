
#ifndef SO_LONG_H
# define SO_LONG_H
# include "../src/libft.h"
# include "../minilibx/mlx.h"

/*typedef struct struct_mlx
{
	void	*mlx;
	void	*mlx_win;
}mlx;*/
typedef struct struct_mlx
{
	void	*mlx;
	void	*win;
    void    *img;
    char	**relative_path;
	char	**map;
    int		img_width;
	int		img_height;

}t_mlx;
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype	type;
	t_tiletype	og_type;
	t_vector	position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;
#endif
