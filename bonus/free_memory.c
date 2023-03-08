/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:58:37 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 20:27:53 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->v_len)
	{
		free(data->imap->map[i]);
		i++;
	}
	free(data->imap->map);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->v_len)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_exit(t_data *data)
{
	free_imap(data);
	free_map(data);
	mlx_destroy_image(data->mlx, data->bg_img);
	mlx_destroy_image(data->mlx, data->c_img);
	mlx_destroy_image(data->mlx, data->e_img);
	mlx_destroy_image(data->mlx, data->ebg_img);
	mlx_destroy_image(data->mlx, data->left_img);
	mlx_destroy_image(data->mlx, data->right_img);
	mlx_destroy_image(data->mlx, data->up_img);
	mlx_destroy_image(data->mlx, data->w_img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->plr);
	free(data->imap);
}

void	free_wrong(t_data *data)
{
	free_map(data);
	free(data->plr);
	free(data->imap);
}

void	free_mapfree(t_data *data)
{
	free(data->plr);
	free(data->imap);
	mlx_destroy_window(data->mlx, data->win);
}
