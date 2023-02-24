#include "so_long.h"

char **read_map(char *map_name)
{
    int i;
    int fd;
    char **map = NULL;
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
    char *ptr;
    ptr = get_next_line(fd);
    count = 0;
    while(ptr > 0)
    {
        free(ptr);
        ptr = get_next_line(fd);
        count++;
    }
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

void    put_image(t_data *x,int i,int j)
{
    int w;
    int h;
    while (x->map[i])
    {
        h = i * PIXEL;
        j = 0;
        while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
        {
            w = j * PIXEL;
            if(x->map[i][j] == '1')
                mlx_put_image_to_window(x->mlx,x->win,x->w_img,w,h);
            else if(x->map[i][j] == '0')
                mlx_put_image_to_window(x->mlx,x->win,x->bg_img,w,h);
            else if(x->map[i][j] == 'C')
            {
                mlx_put_image_to_window(x->mlx,x->win,x->bg_img,w,h);
                w = (j * PIXEL) + 16;
                h = (i * PIXEL) + 16;
                mlx_put_image_to_window(x->mlx,x->win,x->c_img,w,h);
                w -= 16;
                h -= 16;
            }
            else if(x->map[i][j] == 'P')
            {
                mlx_put_image_to_window(x->mlx,x->win,x->bg_img,w,h);
                mlx_put_image_to_window(x->mlx,x->win,x->p_img,w,h);
            }
            else if(x->map[i][j] == 'E')
            {
                mlx_put_image_to_window(x->mlx,x->win,x->ebg_img,w,h);
                mlx_put_image_to_window(x->mlx,x->win,x->e_img,w,h);
            }  
            j++;
        }
        i++;
    }
}