/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:27:54 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/07 16:55:27 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen((char *)src);
	i = 0;
	if (n <= d)
	{
		return (n + s);
	}
	while (src[i] != '\0' && d + i + 1 < n)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

// #include <stdio.h>

// int main()
// {
// 	char *dest = "Merhaba";
// 	char *src = "42Kocaeli";

// 	printf("%zu",ft_strlcat(dest,src,5));
// }

// dst dizisinin son karakteri null'dan sonra 
// src dizisini ekliyor. dst'den n kadar ilerler.

// "src" parametresinden gelen karakter dizisini "dst" parametresinden gelen
// diziye ekliyor."n" parametresi ise "dst" dizisinin maksimum boyutunu
// belirler.
