#include "so_long.h"

int keyboard(int keycode, t_data *data)
{   
  
    if(keycode == 13 || keycode == 126)
        move_up(data);
    else if(keycode == 1 || keycode == 125)
        move_down(data);
    else if(keycode == 2 || keycode == 124 )
        move_right(data);
    else if(keycode == 0 || keycode == 123 )
        move_left(data);
    else if(keycode == 53)
        close_win();
    return (0);
}