#include "so_long.h"

void    upload_img(t_data *x)
{
    int w;
    int h;
    w = x->h_len * PIXEL;
    h = x->v_len * PIXEL;
    x->mlx = mlx_init();
    x->win = mlx_new_window(x->mlx, w, h, "Hungry Spider");
    x->c_img = mlx_xpm_file_to_image(x->mlx, C, &w, &h);
    x->bg_img = mlx_xpm_file_to_image(x->mlx, BG, &w, &h);
    x->e_img = mlx_xpm_file_to_image(x->mlx, E, &w, &h);
    x->p_img = mlx_xpm_file_to_image(x->mlx, P, &w, &h);
    x->w_img = mlx_xpm_file_to_image(x->mlx, W, &w, &h);
    x->ebg_img = mlx_xpm_file_to_image(x->mlx, EBG, &w, &h);
    x->right_img = mlx_xpm_file_to_image(x->mlx, RGHT,&w, &h);
    x->left_img = mlx_xpm_file_to_image(x->mlx, LFT, &w, &h);
    x->up_img = mlx_xpm_file_to_image(x->mlx, UP, &w, &h);
}

void    upload_map(t_data *data,char *map_name)
{
    data->plr = malloc(sizeof(t_plr));
    data->plr->count = 1;
    data->map_name = map_name;
    mapfree_control(data);
    data->map = read_map(map_name);
    data->h_len = horizontal_len(data->map);
    data->v_len = vertical_len(data->map_name);
    data->v_index = data->v_len - 1;
    data->h_index = data->h_len - 1;
}