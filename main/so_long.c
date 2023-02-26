/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/02/25 23:59:24 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc,char **argv)
{
    t_data data;

    if(argc < 2)
        exit(write(1, "\033[0;31mToo few arguments!\n",27));
    else if(argc > 2)
        exit(write(1, "\033[0;31mToo many arguments!\n",28));
    
    upload_map(&data,argv[1]);
    map_control(&data);
    upload_img(&data);
    put_image(&data,0,0);
    player_locate(&data);
    mlx_hook(data.win, 2, 1L << 0, keyboard,&data);
    // mlx_key_hook(data.win,keyboard,&data);
    mlx_hook(data.win, 17, 0, close_win,0);
    mlx_loop(data.mlx);
}

int close_win(void)
{
    // plr free yap;
    write(1,"\n\033[0;35mGame over! The spider was hungry!\033[0m\n", 46);
    exit(1);
}