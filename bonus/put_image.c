/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:16:31 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/07 15:17:07 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *x, int i, int j)
{
	int	w;
	int	h;

	while (x->map[i])
	{
		h = i * PIXEL;
		j = 0;
		while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
		{
			w = j * PIXEL;
			if (x->map[i][j] == '1')
				mlx_put_image_to_window (x->mlx, x->win, x->w_img, w, h);
			if (x->map[i][j] == '0')
				mlx_put_image_to_window (x->mlx, x->win, x->bg_img, w, h);
			if (x->map[i][j] == 'P')
			{
				mlx_put_image_to_window (x->mlx, x->win, x->bg_img, w, h);
				mlx_put_image_to_window (x->mlx, x->win, x->p_img, w, h);
			}
			j++;
		}
	i++;
	}
	put_image_next (x, 0, 0);
}

void	put_image_next(t_data *x, int i, int j)
{
	int	w;
	int	h;

	while (x->map[i])
	{
		h = i * PIXEL;
		j = 0;
		while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
		{
			w = j * PIXEL;
			if (x->map[i][j] == 'C')
			{
				mlx_put_image_to_window (x->mlx, x->win, x->bg_img, w, h);
				w = (j * PIXEL) + 16;
				h = (i * PIXEL) + 16;
				mlx_put_image_to_window (x->mlx, x->win, x->c_img, w, h);
				w -= 16;
				h -= 16;
			}
			j++;
		}
	i++;
	}
	put_image_next_last (x, 0, 0);
}

void	put_image_next_last(t_data *x, int i, int j)
{
	int	w;
	int	h;

	while (x->map[i])
	{
		h = i * PIXEL;
		j = 0;
		while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
		{
			w = j * PIXEL;
			if (x->map[i][j] == 'E')
			{
				mlx_put_image_to_window (x->mlx, x->win, x->ebg_img, w, h);
				mlx_put_image_to_window (x->mlx, x->win, x->e_img, w, h);
			}
			j++;
		}
	i++;
	}
}
