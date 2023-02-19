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
                exit(write(1, "Map is wrong!",14));
            }
            else
                exit(write(1, "Map is wrong!",14));       
        }
        else
            exit(write(1, "Map is wrong!",14));
    }
    else
        exit(write(1, "Map is wrong!",14));
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
                exit(write(1, "Map is wrong!",14));
            j++;
        }
        i++;
    }
}

void    map_control(t_graph *data)
{
    map_name_control(data->map_name);
    control_components(data->map);
    count_component(data);
}