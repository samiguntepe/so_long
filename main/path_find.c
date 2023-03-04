/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:51:04 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/04 22:22:22 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    path_find(int h,int w,t_data *x,int **imap)
{
    if(x->map[h+1][w] != '1' && imap[h+1][w] < 1)
    {
        imap[h+1][w] = imap[h][w] + 1;
        x->iMap->f_space--;
        path_find(h+1,w,x,x->iMap->map);
    }
    if(x->map[h-1][w] != '1' && imap[h-1][w] < 1)
    {
        imap[h-1][w] = imap[h][w] + 1;
        x->iMap->f_space--;
        path_find(h-1,w,x,x->iMap->map);
    }
    if(x->map[h][w+1] != '1' && imap[h][w+1] < 1)
    {
        imap[h][w+1] = imap[h][w] + 1;
        x->iMap->f_space--;
        path_find(h,w+1,x,x->iMap->map);
    
    }
    if(x->map[h][w-1] != '1' && imap[h][w-1] < 1)
    {
        imap[h][w-1] = imap[h][w] + 1;
        x->iMap->f_space--;
        path_find(h,w-1,x,x->iMap->map);
    }
    return;
}
