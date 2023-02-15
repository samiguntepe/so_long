#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libs/ft_lib/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>
#include <stdio.h>
#define IMG_SIZE 64
#define WIDTH 50
#define HEIGHT 50

typedef struct s_graph
{
    char **map;
    void *mlx_ptr;
    void *win_ptr;
    char *p_img;
    char *e_img;
    char *c_img;
    char *w_img;
    char *bg_img;
} t_graph;

char    *read_map(int fd);
void    map_upload(int fd);
int     x_size(char *map);
int     y_size(char *map);


#endif