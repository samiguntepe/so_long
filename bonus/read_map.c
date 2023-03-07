/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:58:50 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/07 16:35:20 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map_name)
{
	int		i;
	int		fd;
	int		vlen;
	char	**map;

	vlen = vertical_len(map_name);
	map = malloc(sizeof(char *) * vlen + 1);
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

int	vertical_len(char *map_name)
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
	close(fd);
	return (count);
}

int	horizontal_len(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n')
		i++;
	return (i);
}
