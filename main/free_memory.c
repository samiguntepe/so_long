#include "so_long.h"

void	free_imap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h_len)
	{
		free(data->imap->map[i]);
		i++;
	}
}

void	free_map(t_data *data)
{
    int	i;

	i = 0;
	while (i < data->h_len)
	{
		free(data->map[i]);
		i++;
	}
}

void	free_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	
}