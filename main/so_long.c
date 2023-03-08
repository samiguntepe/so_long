/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 21:15:02 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit (ft_printf("\033[0;31mError\nToo few arguments!\n"));
	else if (argc > 2)
		exit (ft_printf("\033[0;31mError\nToo many arguments!\n"));
	upload_map (&data, argv[1]);
	map_control (&data);
	upload_img (&data);
	put_image (&data, 0, 0);
	mlx_hook (data.win, 2, 1L << 0, keyboard, &data);
	mlx_hook (data.win, 17, 0, press_close_key, &data);
	mlx_loop (data.mlx);
}

int	press_close_key(t_data *data)
{
	ft_printf("\n\033[0;35mGame over! The spider was hungry!\033[0m\n");
	exit(1);
}

int	close_win(t_data *data)
{
	ft_printf("\n\033[0;35mGame over! The spider was hungry!\033[0m\n");
	free_exit(data);
	exit(1);
}

int finish_close_win(t_data *data)
{
	free_exit(data);
	exit(1);
}

void	error_messages(int i, t_data *data)
{
	if (i == 1)
	{
		free_wrong(data);
		exit(ft_printf("\033[0;31mError\nWrong Map!(Argument)\n"));
	}
	else if (i == 2)
	{
		exit(ft_printf("\033[0;31mError\nWrong Map!(Components)\n"));
	}
	else if (i == 3)
	{
		free_wrong(data);
		exit(ft_printf("\033[0;31mError\nWrong Map!(Open Map)\n"));
	}
	else if (i == 4)
	{
		free_wrong(data);
		ft_printf("\033[0;31mError\nWrong Map!(Collectible Count)\n");
		exit(1);
	}
}
