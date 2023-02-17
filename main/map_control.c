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