#include "so_long.h"

void    map_name_control(char *map_name)
{
    int len;
    len = ft_strlen(map_name);
    if(map_name[--len] == 'r')
    {
        if(map_name[--len] == 'e')
        {
            if(map_name[--len] == 'b')
            {
                if(map_name[--len] == '.');
                else
                exit(write(1, "Map is wrong! (Argument is wrong)",34));
            }
            else
                exit(write(1, "Map is wrong! (Argument is wrong)",34));       
        }
        else
            exit(write(1, "Map is wrong! (Argument is wrong)",34));
    }
    else
        exit(write(1, "Map is wrong! (Argument is wrong)",34));
}

void    control_components(char **map)
{
    int i;
    int j;
    i = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\0' && map[i][j] != '\n')
        {
            if(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P' ||
            map[i][j] == 'C' || map[i][j] == 'E');
            else
                exit(write(1, "Map is wrong! (Different components)",37));
            j++;
        }
        i++;
    }
}

void    rectangular(t_data *x,int i,int j)
{
    int area;
    int count;
    int a = (x->v_len);
    int b = (x->h_len);
    area = a * b;
    count = 0;
    while (x->map[i])
    {
        j = 0;
        while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
        {
            if(x->map[i][j] == '0' || x->map[i][j] == '1' || x->map[i][j] == 'P' ||
            x->map[i][j] == 'C' || x->map[i][j] == 'E')
                count++;
            else
                exit(write(1, "Map is wrong! (Different components)",37));
            j++;
        }
        i++;
    }
    if(count != area)
        exit(write(1, "Map is wrong! (Map is not rectangular)",39));
}

void    mapfree_control(t_data *x)
{
    int fd;
    char *tmp;
    fd = open(x->map_name,O_RDONLY);
    
    tmp = get_next_line(fd);
    if(tmp == NULL)
    {
        exit(write(1, "Map is wrong! (Map is free)",28));
    }
    free(tmp);
}

void    map_control(t_data *data)
{
    map_name_control(data->map_name);
    control_components(data->map);
    count_component(data);
    rectangular(data,0,0);
    closed_map(data,0,0,0);
    // player_locate(data);
}