/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:40:19 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/10 18:02:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

// #include <stdio.h>

// int	main(){

// 	char dizi[] = "Merhaba42";
// 	printf("%s",(char *)ft_memset(dizi,'c',3));

//     return 0;
// }

// "c" parametresi ile gösterilen bellek bölgesindeki karakteri dest
// parametresindeki bellek bölgesinin ilk "n" parametre değeri kadar byte'ına
// kopyalar.