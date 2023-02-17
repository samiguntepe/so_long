#include "so_long.h"

int keyboard(int keycode, t_graph *data)
{
    if(keycode == 13 || keycode == 126) // W / Yukarı
        move_up(data);
    else if(keycode == 1 || keycode == 125) // S / Aşağı
        move_down(); 
    else if(keycode == 2 || keycode == 124) // D / Sağ 
        move_right();
    else if(keycode == 0 || keycode == 123) // A / Sol
        move_left();
    return (0);
}

void    move_up(t_graph *data,int i,int j)
{
    while(data->map[i])
    {
        while(data->map[i][j] != '\n' || data->map[i][j] != '\0')
        {
            if(data->map[i][j] == 'P')
            {
                
            }
        }
    }
}