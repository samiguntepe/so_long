#include "so_long.h"

void    count_component(t_graph *data)
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
        exit(write(1, "Map is wrong! (Exit count is wrong!)",37));
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
        exit(write(1, "Map is wrong! (Player count is wrong!)",39));
}