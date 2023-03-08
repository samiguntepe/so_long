/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:59:10 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/08 21:16:11 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
		move_up(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 2 || keycode == 124)
		move_right(data);
	else if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 53)
		close_win(data);
	finish_game(data);
	return (0);
}

void	finish_game(t_data *x)
{
	if (x->map[x->plr->h][x->plr->w] == 'C')
	{
		x->plr->coin--;
		x->map[x->plr->h][x->plr->w] = '0';
	}
	if (x->plr->coin == 0)
	{
		if (x->map[x->plr->h][x->plr->w] == 'E')
		{
			ft_printf("\n\033[32mCongratulations!\033[0m");
			finish_close_win(x);
		}
	}
}
