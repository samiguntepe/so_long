/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:43:26 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/06 14:54:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_move_img(t_data *x)
{
    black_rectangular(x);
    mlx_string_put(x->mlx,x->win, 4, 15, 52224, "MOVE:");
    mlx_string_put(x->mlx,x->win, 40, 15, 52224, ft_itoa(x->plr->wcount));
}

void    black_rectangular(t_data *xx)
{
    
    int x;
    int y;
    
    y = 0;
    while (y <= 20)
    {
        x = 0;
        while (x <= 64)
        {
            mlx_pixel_put(xx->mlx, xx->win, x, y, 00000000);
            x++;
        }
        y++;
    }
}