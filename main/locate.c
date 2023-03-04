/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:13 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/04 08:08:46 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    player_locate(t_data *x)
{
    int i;
    int j;

    i = 0;
     while(x->map[i])
    {
        j = 0;
        while(x->map[i][j] != '\n' && x->map[i][j] != '\0')
        {
            if(x->map[i][j] == 'P')
            {
                x->plr->h = i;
                x->plr->w = j;
            }
            j++;
        }
        i++;
    }
}