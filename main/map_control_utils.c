/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:58:58 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/01 14:00:01 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    count_component(t_data *data)
{
    c_count(data,0,0);
    e_count(data->map,0,0);
    p_count(data->map,0,0);
}

void    c_count(t_data *x,int w,int h)
{
    x->plr->coin = 0;
    while (x->map[h])
    {
        w = 0;
        while (x->map[h][w] != '\0' && x->map[h][w] != '\n')
        {
            if(x->map[h][w] == 'C')
                x->plr->coin++;
            w++;
        }
        h++;
    }
    if(x->plr->coin <= 0)
        error_messages(4);
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
        exit(ft_printf("\033[0;31mError\nWrong Map! (Exit Count)\n"));
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
        exit(ft_printf("\033[0;31mError\nWrong Map!(Player Count)\n"));
}

void    closed_map(t_data *x,int i,int j,int m)
{
    while (x->map[i])
    {
        j = 0;
        while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
        {
            if(x->map[0][j] != '1')
                error_messages(3);
            else if(x->map[i][0] != '1')
                error_messages(3);
            j++;
        }
        m = 0;
        while(x->map[i][m] != '\0' && x->map[i][m] != '\n')
        {
            if(x->map[(i)][x->h_index] != '1')
                error_messages(3);
            if(x->map[(x->v_index)][m] != '1')
                error_messages(3);
            m++;
        }
        i++;
    }
}