/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:13 by sguntepe          #+#    #+#             */
/*   Updated: 2023/02/25 23:59:14 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    player_locate(t_data *x)
{
    ft_printf("\033[1;40m\rMove:\033[0m");
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