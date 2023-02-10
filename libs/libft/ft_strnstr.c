/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:06:06 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/17 20:55:50 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(needle);
	if (!s2_len)
		return ((char *)haystack);
	if (len != 0)
	{
		while (haystack[i] && i <= len - s2_len)
		{
			j = 0;
			while (needle[j] && needle[j] == haystack[i + j])
				j++;
			if (j == s2_len)
				return ((char *)&haystack[i]);
			i++;
		}
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char hstack[] = "Merhaba42Kocaeli";
// 	char needle[] = "42";

// 	printf("%s",ft_strnstr(hstack,needle,10));
// }

// "needle(iğne)" yi "haystack(samanlık)" da "len" kadar arar.
// bulduğu zaman devamını da döndürür.
