/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:21:08 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 17:26:30 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_uc;
	const unsigned char	*s2_uc;
	size_t				index;

	index = 0;
	s1_uc = (const unsigned char *)s1;
	s2_uc = (const unsigned char *)s2;
	while (index < n)
	{
		if (s1_uc[index] != s2_uc[index])
			return (s1_uc[index] - s2_uc[index]);
		index++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char *s1 = "42KOCAELI";
// 	char *s2 = "42KOCAELI";

// 	printf("%d",ft_memcmp(s1,s2,9));
// }

// "s1" parametresi ile gösterilen bellek bölgesinin "n" parametre değeri
// kadar ilk byte'ını "s2" parametresi ile gösterilen bellek bölgesi ile
// karşılaştırır. Eğer her iki bellek bölgesindeki tüm değerler aynı 
// ise sıfır değeri, aksi takdirde sıfırdan farklı bir değer geri döndürür.
