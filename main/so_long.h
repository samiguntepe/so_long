#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libs/ft_lib/libft.h"
# include "../libs/minilibx/mlx.h"
# include <fcntl.h>
#include <stdio.h>

#define PIXEL 64

// textures path
#define C "./textures/c.xpm"
#define BG "./textures/bg.xpm"
#define E "./textures/e.xpm"
#define P "./textures/p.xpm"
#define W "./textures/w.xpm"
#define EBG "./textures/ebg.xpm"


typedef struct s_graph
{
    void *mlx;
    void *win;
    char **map;
    char *p_img;
    char *e_img;
    char *c_img;
    char *w_img;
    char *bg_img;
    char *ebg_img;
    char *map_name;
    int  v_len;
    int  h_len;
    char **(*readf)(char *);
} t_graph;



char    **read_map(char *map_name);

int     vertical_len(char *map_name);
int     horizontal_len(char **map);
int     close_win(t_graph *data);

void    put_image(t_graph *d,int i,int j);
void    upload_img(t_graph *x);
void    map_name_control(char *map_name);
void    control_components(char **map);
void    map_control(t_graph *data);
void    upload_map(t_graph *data,char *map_name);
void    c_count(char **map,int w,int h);
void    e_count(char **map,int w,int h);
void    p_count(char **map,int w,int h);

void    count_component(t_graph *data);
// int     keyboard(int keycode, t_graph *data);

#endif