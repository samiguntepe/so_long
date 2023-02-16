#include "so_long.h"

char **read_map(t_graph *graph,char *map_name)
{
    int i;
    int fd;
    char **map;
    int vlen = vertical_len(map_name);
    map = malloc(sizeof(char *) * vlen + 1);
    i = 0;
    fd = open(map_name,O_RDONLY);
    while (i < vlen)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

int vertical_len(char *map_name)
{
    int count;
    int fd = open(map_name,O_RDONLY);
    count = 0;
    while(get_next_line(fd) > 0)
    {
        count++;
    }
    close(fd);
    return count;
}

int horizontal_len(char **map)
{
    int i;
    i = 0;
    while(map[0][i] != '\n')
        i++;
    return (i);
}

void    put_image(t_graph *d,char **map,int i,int j)
{
    int w;
    int h;
    while (map[i])
    {
        h = i * PIXEL;
        j = 0;
        while (map[i][j] != '\0')
        {
            w = j * PIXEL;
            if(map[i][j] == '1')
                mlx_put_image_to_window(d->mlx_ptr,d->win_ptr,d->w_img,w,h);
            else if(map[i][j] == '0')
                mlx_put_image_to_window(d->mlx_ptr,d->win_ptr,d->bg_img,w,h);
            else if(map[i][j] == 'C')
                mlx_put_image_to_window(d->mlx_ptr,d->win_ptr,d->c_img,w,h);
            else if(map[i][j] == 'P')
                mlx_put_image_to_window(d->mlx_ptr,d->win_ptr,d->p_img,w,h);
            else if(map[i][j] == 'E')
                mlx_put_image_to_window(d->mlx_ptr,d->win_ptr,d->e_img,w,h);
            else
                exit(write(1, "Map is wrong!",14));
            j++;
        }
        i++;
    }
}

void upload_img(t_graph *x,char *map_name)
{
    int w;
    int h;
    x->map = read_map(x,map_name);
    w = horizontal_len(x->map) * PIXEL;
    h = vertical_len(map_name) * PIXEL;
    x->mlx_ptr = mlx_init();
    x->win_ptr = mlx_new_window(x->mlx_ptr, w, h, "Goblin!");
    x->c_img = mlx_xpm_file_to_image(x->mlx_ptr, "../sprite/c.xpm", &w, &h);
    x->bg_img = mlx_xpm_file_to_image(x->mlx_ptr, "../sprite/bg.xpm", &w, &h);
    x->e_img = mlx_xpm_file_to_image(x->mlx_ptr, "../sprite/d_c.xpm", &w, &h);
    x->p_img = mlx_xpm_file_to_image(x->mlx_ptr, "../sprite/p.xpm", &w, &h);
    x->w_img = mlx_xpm_file_to_image(x->mlx_ptr, "../sprite/w.xpm", &w, &h);
}