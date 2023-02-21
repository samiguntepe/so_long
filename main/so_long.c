#include "so_long.h"

int main(int argc,char **argv)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    data->plyr = malloc(sizeof(t_plyr));
    if(argc < 2)
        exit(write(1, "\033[0;31mToo few arguments!\033[0m\n",31));
    else if(argc > 2)
        exit(write(1, "\033[0;31mToo many arguments!\033[0m\n",32));
        
    upload_map(data,argv[1]);
    map_control(data);
    upload_img(data);
    put_image(data,0,0);
    mlx_hook(data->win, 2, 1L << 0, keyboard, &data);
    mlx_hook(data->win, 17, 0, close_win, &data);
    mlx_loop(data->mlx);
}

int close_win(t_data *data)
{
    write(1,"\033[0;35mGame is closed and the spider is hungry!\033[0m\n",53);
    exit(0);
}