/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:04 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 20:53:11 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *x)
{
	int	h;
	int	w;
	int	bg_h;

	if (x->map[x->plr->h -1][x->plr->w] == '1')
		return ;
	bg_h = (x->plr->h) * PIXEL;
	(x->plr->h) -= 1;
	h = x->plr->h * PIXEL;
	w = x->plr->w * PIXEL;
	mlx_put_image_to_window(x->mlx, x->win, x->bg_img, w, bg_h);
	mlx_put_image_to_window(x->mlx, x->win, x->up_img, w, h);
	fix_exit (x, 0, 0);
	mlx_put_image_to_window(x->mlx, x->win, x->up_img, w, h);
	ft_printf ("\x1B[40m\x1B[32m\rMove:\x1B[0m");
	ft_printf ("\x1B[40m\x1B[32m%d\x1B[0m", x->plr->count++);
	x->plr->wcount++;
	move_count_img(x);
}

void	move_down(t_data *x)
{
	int	h;
	int	w;
	int	bg_h;

	if (x->map[x->plr->h +1][x->plr->w] == '1')
		return ;
	bg_h = (x->plr->h) * PIXEL;
	(x->plr->h) += 1;
	h = x->plr->h * PIXEL;
	w = x->plr->w * PIXEL;
	mlx_put_image_to_window(x->mlx, x->win, x->bg_img, w, bg_h);
	mlx_put_image_to_window(x->mlx, x->win, x->p_img, w, h);
	fix_exit(x, 0, 0);
	mlx_put_image_to_window(x->mlx, x->win, x->p_img, w, h);
	ft_printf ("\x1B[40m\x1B[32m\rMove:\x1B[0m");
	ft_printf ("\x1B[40m\x1B[32m%d\x1B[0m", x->plr->count++);
	x->plr->wcount++;
	move_count_img(x);
}

void	move_right(t_data *x)
{
	int	h;
	int	w;
	int	bg_w;

	if (x->map[x->plr->h][x->plr->w +1] == '1')
		return ;
	bg_w = (x->plr->w) * PIXEL;
	(x->plr->w) += 1;
	w = x->plr->w * PIXEL;
	h = x->plr->h * PIXEL;
	mlx_put_image_to_window(x->mlx, x->win, x->bg_img, bg_w, h);
	mlx_put_image_to_window(x->mlx, x->win, x->right_img, w, h);
	fix_exit(x, 0, 0);
	mlx_put_image_to_window(x->mlx, x->win, x->right_img, w, h);
	ft_printf ("\x1B[40m\x1B[32m\rMove:\x1B[0m");
	ft_printf ("\x1B[40m\x1B[32m%d\x1B[0m", x->plr->count++);
	x->plr->wcount++;
	move_count_img(x);
}

void	move_left(t_data *x)
{
	int	h;
	int	w;
	int	bg_w;

	if (x->map[x->plr->h][x->plr->w -1] == '1')
		return ;
	bg_w = (x->plr->w) * PIXEL;
	(x->plr->w) -= 1;
	w = x->plr->w * PIXEL;
	h = x->plr->h * PIXEL;
	mlx_put_image_to_window(x->mlx, x->win, x->bg_img, bg_w, h);
	mlx_put_image_to_window(x->mlx, x->win, x->left_img, w, h);
	fix_exit(x, 0, 0);
	mlx_put_image_to_window(x->mlx, x->win, x->left_img, w, h);
	ft_printf ("\x1B[40m\x1B[32m\rMove:\x1B[0m");
	ft_printf ("\x1B[40m\x1B[32m%d\x1B[0m", x->plr->count++);
	x->plr->wcount++;
	move_count_img(x);
}

void	fix_exit(t_data *x, int i, int j)
{
	int	w;
	int	h;

	i = 0;
	while (x->map[i])
	{
		j = 0;
		while (x->map[i][j] != '\n' && x->map[i][j] != '\0')
		{
			if (x->map[i][j] == 'E')
			{
				w = j * PIXEL;
				h = i * PIXEL;
				mlx_put_image_to_window(x->mlx, x->win, x->ebg_img, w, h);
				mlx_put_image_to_window(x->mlx, x->win, x->e_img, w, h);
			}
			j++;
		}
		i++;
	}
}
