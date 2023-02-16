#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libs/ft_lib/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>
#include <stdio.h>
#define PIXEL 64

typedef struct s_graph
{
    void *mlx_ptr;
    void *win_ptr;
    char **map;
    char *p_img;
    char *e_img;
    char *c_img;
    char *w_img;
    char *bg_img;
    int  v_len;
    int  h_len;
} t_graph;


char    **read_map(t_graph *graph,char *map_name);
int     vertical_len(char *map_name);
int     horizontal_len(char **map);
void    put_image(t_graph *d,char **map,int i,int j);
void    upload_img(t_graph *x,char *map_name);

#endif