/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:51:04 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/01 16:51:05 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    path_find(int h,int w,char old,char new,t_data *x)
{

    if(x->uMap->map[h][w] != new)
    {
        path_find_move(x);

        path_find(x->uMap->h,x->uMap->w,'0',)

        

    }
    return;
}

void    up_path(t_data *x)
{       
    if(x->uMap->map[(x->uMap->h) - 1][x->uMap->w] != '1')
    {
        x->uMap->map[x->uMap->h][x->uMap->w] = '1';
        x->uMap->h--;
        x->uMap->f_space--;
    }
    else
        return;
}

void    down_path(t_data *x)
{
    if(x->uMap->map[(x->uMap->h) + 1][x->uMap->w] != '1')
    {
        x->uMap->map[x->uMap->h][x->uMap->w] = '1';
        x->uMap->h++;
        x->uMap->f_space--;
    }
    else
        return;
}

void    right_path(t_data *x)
{
    if(x->uMap->map[x->uMap->h][(x->uMap->w) + 1] != '1')
    {
        x->uMap->map[x->uMap->h][x->uMap->w] = '1';
        x->uMap->w++;
        x->uMap->f_space--;
    }
    else
        return;
}

void    left_path(t_data *x)
{
    if(x->uMap->map[x->uMap->h][(x->uMap->w) - 1] != '1')
    {
        x->uMap->map[x->uMap->h][x->uMap->w] = '1';
        x->uMap->w--;
        x->uMap->f_space--;
    }
    else
        return;
}

