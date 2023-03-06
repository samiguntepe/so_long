/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:01 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/04 22:52:26 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
                    error_messages(1);
            }
            else
                error_messages(1);    
        }
        else
            error_messages(1);
    }
    else
        error_messages(1);
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
                error_messages(2);
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
                error_messages(2);
            j++;
        }
        i++;
    }
    if(count != area)
        exit(ft_printf("\033[0;31mError\nWrong Map!(Rectangular)\n"));
}

void    mapfree_control(t_data *x)
{
    int fd;
    char *tmp;
    fd = open(x->map_name,O_RDONLY);
    tmp = get_next_line(fd);
    if(tmp == NULL)
    {
        exit(ft_printf("\033[0;31mError\nWrong Map!(Free Map)\n"));
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
    count_free_space(data);
    path_find((data->plr->h),(data->plr->w),data,data->iMap->map);
    if(data->iMap->f_space == 1);
    else
    {
        ft_printf("\033[0;31mError\nImpossible to finish the game!\n");
        exit(1);
    }
        
    ft_printf("\033[1;40m\rMove:\033[0m");
}