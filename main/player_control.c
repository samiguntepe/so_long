#include "so_long.h"

int keyboard(int keycode, t_data *data)
{
    if(keycode == 13 || keycode == 126); // W / Yukarı
        // move_up(data)
    else if(keycode == 1 || keycode == 125); // S / Aşağı
        // printf("S");
    else if(keycode == 2 || keycode == 124); // D / Sağ 
        // printf("D");
    else if(keycode == 0 || keycode == 123); // A / Sol
        // printf("W");
    else if(keycode == 53)
        close_win(data);
    return (0);
}

// void    move_up(t_data *x)
// {
    
// }