/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:28 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/04 21:24:09 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libs/ft_printf/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/minilibx/mlx.h"
#include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>

#define PIXEL 64

// textures path
#define C "./textures/c.xpm"
#define BG "./textures/bg.xpm"
#define E "./textures/e.xpm"
#define P "./textures/p.xpm"
#define W "./textures/w.xpm"
#define EBG "./textures/ebg.xpm"
#define LFT "./textures/p_left.xpm"
#define RGHT "./textures/p_right.xpm"
#define UP "./textures/p_up.xpm"


typedef struct s_iMap
{
  int f_space;
  int h;
  int w;
  int **map;
}t_iMap;

typedef struct s_plr
{
  int h;
  int w;
  int count;
  int coin;
} t_plr;


typedef struct s_data
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
    char *left_img;
    char *right_img;
    char *up_img;
    char *map_name;
    int v_len;
    int h_len;
    int v_index;
    int h_index;
    t_plr *plr;
    t_iMap *iMap;
} t_data;



char    **read_map(char *map_name);

int     vertical_len(char *map_name);
int     horizontal_len(char **map);
int     close_win(void);
int     keyboard(int keycode, t_data *data);
void    count_free_space(t_data *x);

void    put_image(t_data *d,int i,int j);
void    upload_img(t_data *x);
void    map_name_control(char *map_name);
void    control_components(char **map);
void    map_control(t_data *data);
void    upload_map(t_data *data,char *map_name);
void    c_count(t_data *x,int w,int h);
void    e_count(char **map,int w,int h);
void    p_count(char **map,int w,int h);
void    error_messages(int i);

void    count_component(t_data *data);
void    rectangular(t_data *x,int i,int j);
void    closed_map(t_data *x,int i,int j,int m);
void    mapfree_control(t_data *x);

void    move_up(t_data *x);
void    move_down(t_data *x);
void    move_right(t_data *x);
void    move_left(t_data *x);
void    fix_exit(t_data *x,int i,int j);
void    player_locate(t_data *x);
void    finish_game(t_data *x);
int    **int_map(char *map_name,t_data *x,int i,int j);
void    path_find(int h,int w,t_data *x,int **imap);


#endif