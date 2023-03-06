/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:51:07 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/04 20:20:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_free_space(t_data *x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (x->map[i])
    {
        j = 0;
        while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
        {
            if(x->map[i][j] != '1')
                x->iMap->f_space++;
            j++;
        }
        i++;
    }
}

int    **int_map(char *map_name,t_data *x,int i,int j)
{
    int vlen;
    int hlen;
    int **map;
    
    hlen = horizontal_len(x->map);
    vlen = vertical_len(x->map_name);
    map = (int **)malloc(sizeof(int *) * vlen + 1);
    while(i < vlen)
    {
        j = 0;
        map[i] = malloc(sizeof(int) * hlen + 1);
        while (j < hlen)
        {
            if(i == x->plr->h && j == x->plr->w)
                map[i][j] = 1;
            else
                map[i][j] = 0;
            j++;
        }
        map[i][j] = '\0';
        i++; 
    }
    map[i] = NULL;
    return map;
}