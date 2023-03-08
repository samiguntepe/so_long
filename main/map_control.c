/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:01 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 21:33:33 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_name_control(char *map_name, t_data *data)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[--len] == 'r')
	{
		if (map_name[--len] == 'e')
		{
			if (map_name[--len] == 'b')
			{
				if (map_name[--len] == '.')
					;
				else
					error_messages(1, data);
			}
			else
				error_messages(1, data);
		}
		else
			error_messages(1, data);
	}
	else
		error_messages(1, data);
}

void	control_components(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P' ||
				map[i][j] == 'C' || map[i][j] == 'E');
			else
				error_messages(2, data);
			j++;
		}
		i++;
	}
}

void	rectangular(t_data *x, int i, int j)
{
	int	area;
	int	count;

	area = (x->h_len) * (x->v_len);
	count = 0;
	while (x->map[i])
	{
		j = 0;
		while (x->map[i][j] != '\0' && x->map[i][j] != '\n')
		{
			if (x->map[i][j] == '0' || x->map[i][j] == '1' ||
			x->map[i][j] == 'P' || x->map[i][j] == 'C' || x->map[i][j] == 'E')
				count++;
			else
				error_messages(2, x);
			j++;
		}
		i++;
	}
	if (count != area)
	{
		free_wrong(x);
		exit (ft_printf ("\033[0;31mError\nWrong Map!(Rectangular)\n"));
	}
}

void	mapfree_control(t_data *x)
{
	int		fd;
	char	*tmp;

	fd = open(x->map_name, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		free_mapfree(x);
		exit (ft_printf ("\033[0;31mError\nWrong Map!\n"));
	}
	free(tmp);
}

void	map_control(t_data *data)
{
	map_name_control(data->map_name, data);
	control_components(data->map, data);
	count_component(data);
	rectangular(data, 0, 0);
	closed_map(data, 0, 0, 0);
	count_free_space(data);
	path_find((data->plr->h), (data->plr->w), data, data->imap->map);
	if (data->imap->f_space == 1)
		;
	else
	{
		free_wrong(data);
		ft_printf("\033[0;31mError\nImpossible to finish the game!\n");
		exit(1);
	}
	ft_printf("\x1B[40m\x1B[32m\rMove:0\x1B[0m");
}
