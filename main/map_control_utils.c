#include "so_long.h"

void    count_component(t_data *data)
{
    c_count(data->map,0,0);
    e_count(data->map,0,0);
    p_count(data->map,0,0);
}

void    c_count(char **map,int w,int h)
{
    int count;

    count = 0;
    while (map[h])
    {
        w = 0;
        while (map[h][w] != '\0' && map[h][w] != '\n')
        {
            if(map[h][w] == 'C')
                count++;
            w++;
        }
        h++;
    }
    if(count <= 0)
        exit(write(1, "Map is wrong! (Collectible is few)",35));
}

void    e_count(char **map,int w,int h)
{
    int count;

    count = 0;
    while (map[h])
    {
        w = 0;
        while (map[h][w] != '\0' && map[h][w] != '\n')
        {
            if(map[h][w] == 'E')
                count++;
            w++;
        }
        h++;
    }
    if(count != 1)
        exit(write(1, "Map is wrong! (Exit count is wrong)",36));
}

void    p_count(char **map,int w,int h)
{
    int count;

    count = 0;
    while (map[h])
    {
        w = 0;
        while (map[h][w] != '\0' && map[h][w] != '\n')
        {
            if(map[h][w] == 'P')
                count++;
            w++;
        }
        h++;
    }
    if(count != 1)
        exit(write(1, "Map is wrong! (Player count is wrong)",38));
}

void    closed_map(t_data *x,int i,int j,int m)
{
    while (x->map[i])
    {
        j = 0;
        while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
        {
            if(x->map[0][j] != '1')
                exit(write(1, "Map is wrong! (Map is not closed)",34));
            else if(x->map[i][0] != '1')
                exit(write(1, "Map is wrong! (Map is not closed)",34));
            j++;
        }
        m = 0;
        while(x->map[i][m] != '\0' && x->map[i][m] != '\n')
        {
            if(x->map[(i)][x->h_index] != '1')
                exit(write(1, "Map is wrong! (Map is not closed)",34));
            if(x->map[(x->v_index)][m] != '1')
                exit(write(1, "Map is wrong! (Map is not closed)",34));
            m++;
        }
        i++;
    }
}