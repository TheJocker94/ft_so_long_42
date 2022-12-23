#include "so_long.h"

int	ft_ylen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != '\n')
		++i;
	return (i);
}

t_tile    *y_dupe(char *str)
{
	int i = 0;
	int len = ft_ylen(str);
	t_tile *y = malloc(sizeof(char) * (len + 1));
	
	//*y[len] = NULL;
	while (i < len)
	{
		y[i].ori_type = str[i];
		++i;
	}
	return (y);
}

void    fill_tilemap(t_tile **array, char *str)
{
	int y_index = 0;	
	
	while (*str != '\0' && *str != '\n')
	{
		array[y_index] = y_dupe(str);
		++y_index;		
        str++;
	}
}


t_tile **ft_tilemap_alloc(char *map, t_mlx *init)
{
    t_tile **tilemap;
    int y = 1;
    int x = 0;
    int i = 0;

    while(map[i])
    {   
        if(y == 1)
            x++;
        if(map[i] == '\n' && map[i+1] != '\0')
                y++;        
        i++;
    }
    init->lines = x - 1;
    init->columns = y;

    tilemap = malloc(sizeof(t_tile *) * (y + 1));
    tilemap[y] = NULL;   
    
    fill_tilemap(tilemap, map);

    return(tilemap);
}

void    ft_init_map(t_mlx init, char *map)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int xbuff = 0;
    int ybuff = 0;
    
    while(map[i])
    {
        if(map[i] == '\n')
        {
            ybuff += SIZE;
            y++;
            xbuff = 0;
            x = 0;
            i++;                       
        } 

        init.map[y][x].position.x = xbuff;
        init.map[y][x].position.y = ybuff;
        init.map[y][x].type = map[i];
        if (x > 0)
        {
            init.map[y][x].left = &init.map[y][x - 1];
        }
        if (y > 0)
        {
            init.map[y][x].up = &init.map[y - 1][x];
        }
        if (x < init.lines)
        {
            init.map[y][x].right = &init.map[y][x + 1];
        }
        if (y < init.columns)
        {
            init.map[y][x].down = &init.map[y + 1][x];
        }
        xbuff += SIZE;
        x++;               
        i++;
    }
}