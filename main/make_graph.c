/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:58:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/06 18:21:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char	*map_name)
{
	int		i;
	int		fd;
	int		vlen;
	char	**map;

	map = malloc(sizeof(char *) * vlen + 1);
	vlen = vertical_len(map_name);
	fd = open(map_name, O_RDONLY);
	i = 0;
	while (i < vlen)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	vertical_len(char	*map_name)
{
	int		count;
	int		fd;
	char	*ptr;

	fd = open(map_name, O_RDONLY);
	ptr = get_next_line(fd);
	count = 0;
	while (ptr > 0)
	{
		free(ptr);
		ptr = get_next_line(fd);
		count++;
	}
	close (fd);
	return (count);
}

int	horizontal_len(char	**map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n')
		i++;
	return (i);
}

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
			else if (x->map[i][j] == '0')
				mlx_put_image_to_window(x->mlx, x->win, x->bg_img, w, h);
			else
				put_image_next(x,i,j,w,h);
			j++;
		}
	i++;
	}
}

void	put_image_next(t_data *x,int i, int j, int w, int h)
{
	if (x->map[i][j] == 'C')
	{
		mlx_put_image_to_window (x->mlx, x->win, x->bg_img, w, h);
		w = (j * PIXEL) + 16;
		h = (i * PIXEL) + 16;
		mlx_put_image_to_window (x->mlx, x->win, x->c_img, w, h);
		w -= 16;
		h -= 16;
	}
	else if (x->map[i][j] == 'P')
	{
		mlx_put_image_to_window (x->mlx, x->win, x->bg_img, w, h);
		mlx_put_image_to_window (x->mlx, x->win, x->p_img, w, h);
	}
	else if (x->map[i][j] == 'E')
	{
		mlx_put_image_to_window (x->mlx, x->win, x->ebg_img, w, h);
		mlx_put_image_to_window (x->mlx, x->win, x->e_img, w, h);
			}
}
