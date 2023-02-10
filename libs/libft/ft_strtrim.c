/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:30:29 by sguntepe          #+#    #+#             */
/*   Updated: 2022/11/26 17:00:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	m = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (start < end)
		m[i++] = s1[start++];
	m[i] = '\0';
	return (m);
}

// #include <stdio.h>

// int main()
// {
// 	char s1[] = "xxMerhaba42Kocaelixcss";
// 	char set[] = "xcs";

// 	printf("%s",ft_strtrim(s1,set));
// }

// s1 dizisinin başında ve sonunda set karakterlerini arar bulduğu zaman kırpar.
