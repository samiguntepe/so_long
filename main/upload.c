#include "so_long.h"

void    upload_img(t_graph *x)
{
    int w;
    int h;
    w = horizontal_len(x->map) * PIXEL;
    h = vertical_len(x->map_name) * PIXEL;
    x->mlx = mlx_init();
    x->win = mlx_new_window(x->mlx, w, h, "Spider Hunt");
    x->c_img = mlx_xpm_file_to_image(x->mlx, C, &w, &h);
    x->bg_img = mlx_xpm_file_to_image(x->mlx, BG, &w, &h);
    x->e_img = mlx_xpm_file_to_image(x->mlx, E, &w, &h);
    x->p_img = mlx_xpm_file_to_image(x->mlx, P, &w, &h);
    x->w_img = mlx_xpm_file_to_image(x->mlx, W, &w, &h);
    x->ebg_img = mlx_xpm_file_to_image(x->mlx, EBG, &w, &h);
}

void    upload_map(t_graph *data,char *map_name)
{
    data->readf = &read_map;
    data->map = (**data->readf)(map_name);
    data->map_name = map_name;
}