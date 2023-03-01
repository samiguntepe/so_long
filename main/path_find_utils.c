/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:51:07 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/01 16:51:08 by sguntepe         ###   ########.fr       */
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
                x->uMap->f_space++;
            j++;
        }
        i++;
    }
}

void    path_find_move(t_data *x)
{
    up_path(x);
    down_path(x);
    right_path(x);
    left_path(x);
}