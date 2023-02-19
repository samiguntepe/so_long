#include "so_long.h"
int main(int argc,char **argv)
{
    t_graph *data;
    data = malloc(sizeof(t_graph));
    if(argc < 2)
        exit(write(1, "Too few arguments!",19));
    else if(argc > 2)
        exit(write(1, "Too many arguments!",20));
    upload_map(data,argv[1]);
    map_control(data);
    upload_img(data);
    put_image(data,0,0);
    // mlx_hook(data->win_ptr, 2, 1L << 0, keyboard, &data);
    mlx_hook(data->win, 17, 0, close_win, &data);
    mlx_loop(data->mlx);
}

int close_win(t_graph *data)
{
    write(1,"You closed the game and the spider is hungry!",46);
    exit(0);
}