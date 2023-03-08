/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:39:03 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 21:08:02 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_count_img(t_data *x)
{
	char	*str;

	str = ft_itoa(x->plr->wcount);
	black_rectangular(x);
	mlx_string_put(x->mlx, x->win, 4, 15, 52224, "MOVE:");
	mlx_string_put(x->mlx, x->win, 40, 15, 52224, str);
	free(str);
}

void	black_rectangular(t_data *xx)
{
	int	x;
	int	y;

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
