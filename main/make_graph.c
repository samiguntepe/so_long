#include "so_long.h"

// read map line
char *read_map(int fd)
{
    char *get_line;
    char *map;
    map = NULL;

    get_line = get_next_line(fd);
    while (get_line)
    {
        map = ft_gnl_strjoin(map, get_line);
        free(get_line);
        get_line = get_next_line(fd);
    }
    free(get_line);
    return map;
}

int x_size(char *map)
{
    int i;
    i = 0;
    while(map[i])
    {
        if(map[i] == '\n')
            break;
        i++;
    }
    return i;
}

int y_size(char *map)
{
    int i;
    int count;
    count = 1;
    i = 0;
    while(map[i])
    {
        if(map[i] == '\n')
            count++;
        i++;
    }
    return count;
}

void    map_upload(int fd)
{
    t_graph *data = malloc(sizeof(t_graph));
    int x_len = x_size(read_map(fd));
    // int y_len = y_size(read_map(fd));
    char *map = read_map();
    printf("%d\n",x_len);
    printf("%s\n",map);
    // printf("%d\n",y_len);
}


