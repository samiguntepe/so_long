/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:51:04 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/03 23:43:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    path_find(int h,int w,t_data *x)
// {
    
    
//     if(x->uMap->map[h+1][w] != '1')
//     {
        
//         ft_printf("\n\n%s",x->uMap->map[0]);
//         ft_printf("%s",x->uMap->map[1]);
//         ft_printf("%s",x->uMap->map[2]);
//         ft_printf("%s",x->uMap->map[3]);
//         ft_printf("%s\n",x->uMap->map[4]);
//         x->uMap->map[h][w] = '1';
//         x->uMap->f_space--; 
//         path_find(h+1,w,x);
//     }
//     else if(x->uMap->map[h-1][w] != '1')
//     {
//         ft_printf("\n\n%s",x->uMap->map[0]);
//         ft_printf("%s",x->uMap->map[1]);
//         ft_printf("%s",x->uMap->map[2]);
//         ft_printf("%s",x->uMap->map[3]);
//         ft_printf("%s\n",x->uMap->map[4]);
//         x->uMap->map[h][w] = '1';
//         x->uMap->f_space--;
    
//          if(x->uMap->map[h-1][w] != 'E')
//         {
            
//         path_find(h-1,w,x);

//         }
    
//     }
//     else if(x->uMap->map[h][w+1] != '1')
//     {
//         ft_printf("\n\n%s",x->uMap->map[0]);
//         ft_printf("%s",x->uMap->map[1]);
//         ft_printf("%s",x->uMap->map[2]);
//         ft_printf("%s",x->uMap->map[3]);
//         ft_printf("%s\n",x->uMap->map[4]);
//         x->uMap->map[h][w] = '1';
//         x->uMap->f_space--;
//         if(x->uMap->map[h][w+1] != 'E')
//         {
//         path_find(h,w+1,x);

//         }
    
//     }
//     else if(x->uMap->map[h][w-1] != '1')
//     {
//         ft_printf("\n\n%s",x->uMap->map[0]);
//         ft_printf("%s",x->uMap->map[1]);
//         ft_printf("%s",x->uMap->map[2]);
//         ft_printf("%s",x->uMap->map[3]);
//         ft_printf("%s\n",x->uMap->map[4]);
//         x->uMap->map[h][w] = '1';
//         x->uMap->f_space--;
//         if(x->uMap->map[h][w-1] != 'E')
//         {
//         path_find(h,w-1,x);

//         }
        
        
//     }
//     if (x->uMap->f_space == 0)
//     {
//         ft_printf("\nMap Kabul Edildi!");
//         return;
//     }
//     return;
// }
