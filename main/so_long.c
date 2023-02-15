#include "so_long.h"

int main(int argc,char **argv)
{
    // void *mlx_ptr = mlx_init();

    if(argc < 2)
        exit(write(1, "Too few arguments", sizeof("Too few arguments")));
    else if(argc > 2)
        exit(write(1, "Too many arguments", sizeof("Too many arguments")));

    int fd = open("./maps/map1.ber",O_RDONLY);
    // printf("%s",read_map(fd));

    map_upload(fd);
    // mlx_loop(mlx_ptr);
    return 0;
}