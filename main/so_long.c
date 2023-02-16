#include "so_long.h"

int main(int argc,char **argv)
{
    t_graph *data;
    data = malloc(sizeof(t_graph));
    if(argc < 2)
        exit(write(1, "Too few arguments",18));
    else if(argc > 2)
        exit(write(1, "Too many arguments",19));
    
    
    upload_img(data,argv[1]);
    put_image(data,data->map,0,0);
    
    mlx_loop(data->mlx_ptr);
    return 0;
}