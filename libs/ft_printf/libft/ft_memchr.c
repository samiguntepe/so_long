/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:52:57 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/07 16:55:02 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*(str++) == (unsigned char )c)
			return ((void *)(str - 1));
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = "42Kocaeli";
// 	printf("%s", (char *)ft_memchr(s,'a',6));
// }

// "s" parametresi ile gösterilen bellek bölgesinin "n" parametre değeri kadar
// ilk byte'ında "c" parametresi ile gösterilen değerin (unsigned char olarak
// değerlendirilir) ilk geçtiği yeri arar ve bu bellek adresini gösteren
// bir işaretçi geri döndürür.
