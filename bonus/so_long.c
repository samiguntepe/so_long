/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/06 18:09:08 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc,char **argv)
{
    t_data data;

    if(argc < 2)
        exit(ft_printf("\033[0;31mError\nToo few arguments!\n"));
    else if(argc > 2)
        exit(ft_printf("\033[0;31mError\nToo many arguments!\n"));
    
    upload_map(&data,argv[1]);
    map_control(&data);
    upload_img(&data);
    put_image(&data,0,0);
    put_move_img(&data);
    mlx_hook(data.win, 2, 1L << 0, keyboard,&data);
    mlx_hook(data.win, 17, 0, close_win,0);
    mlx_loop(data.mlx);
}

int close_win(void)
{
    ft_printf("\n\033[0;35mGame over! The spider was hungry!\033[0m\n");
    exit(1);
}

void    error_messages(int i)
{
    if (i == 1)
        exit(ft_printf("\033[0;31mError\nWrong Map!(Argument)\n"));
    else if (i == 2)
        exit(ft_printf("\033[0;31mError\nWrong Map!(Components)\n"));
    else if (i == 3)
        exit(ft_printf("\033[0;31mError\nWrong Map!(Open Map)\n"));
    else if (i == 4)
    {
        ft_printf("\033[0;31mError\nWrong Map!(Collectible Count)\n");
        exit(1);
    }
}