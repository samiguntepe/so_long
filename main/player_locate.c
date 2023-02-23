#include "so_long.h"

void    player_locate(t_data *x)
{
    int i;
    int j;

    i = 0;
     while(x->map[i])
    {
        j = 0;
        while(x->map[i][j] != '\n' && x->map[i][j] != '\0')
        {
            if(x->map[i][j] == 'P')
            {
                x->plr->h = i;
                x->plr->w = j;
            }
            j++;
        }
        i++;
    }
}