#include "so_long.h"

int main(int argc,char **argv)
{
    t_graph *data;
    data = malloc(sizeof(t_graph));
    if(argc < 2)
        exit(write(1, "Too few arguments!",19));
    else if(argc > 2)
        exit(write(1, "Too many arguments!",20));
    map_name_control(argv[1]);
    upload_img(data,argv[1]);
    put_image(data,data->map,0,0);

    mlx_hook(data->win_ptr, 2, 1L << 0, keyboard, &data);
    mlx_hook(data->win_ptr, 17, 0, close_win, &data);
    mlx_loop(data->mlx_ptr);
    return 0;
}

int close_win(t_graph *data)
{
    write(1,"Oyunu kapattınız ve Goblin zindandan kaçamadı!",49);
    exit(0);
}