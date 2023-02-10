/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:55:24 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/10 17:58:14 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
	{
		while (n--)
			*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	}
	return (dst);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "kocaeli";

// 	printf("%s",(char *)ft_memmove(str+2,str,3));
// }

// Memcopy ile aynı işlevi yapar fakat 
// bellekte overlop olmaması için tersten kopyalar.
