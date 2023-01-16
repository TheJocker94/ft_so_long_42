#include "so_long.h"

void move_up_logic(t_mlx *init, int x, int y)
{
    init->map[y][x].up->type = 'P';
	ft_print_and_destroy(init, init->kingo_img.current_img, x, y - 1);
	init->kingo.y = y - 1;
	init->map[y][x].type = '0';
	ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	init->moves += 1;
}

void move_down_logic(t_mlx *init, int x, int y)
{
    init->map[y][x].down->type = 'P';
	ft_print_and_destroy(init, init->kingo_img.current_img, x, y + 1);
	init->kingo.y = y + 1;
	init->map[y][x].type = '0';
	ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	init->moves += 1;
}

void move_left_logic(t_mlx *init, int x, int y)
{
    init->map[y][x].left->type = 'P';
    ft_print_and_destroy(init, init->kingo_img.current_img, x - 1, y);
	init->kingo.x = x - 1;
	init->map[y][x].type = '0';
	ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	init->moves += 1;
}

void move_right_logic(t_mlx *init, int x, int y)
{
    init->map[y][x].right->type = 'P';
	ft_print_and_destroy(init, init->kingo_img.current_img, x + 1, y);
	init->kingo.x = x + 1;
	init->map[y][x].type = '0';
	ft_print_and_destroy(init, "sprites/wall/floor.xpm", x, y);
	init->moves += 1;
}
