/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:45:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 13:39:40 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dizi;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (NULL);
	dizi[len] = '\0';
	while (nbr > 0)
	{
		dizi[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		dizi[0] = '-';
	if (n == 0)
		dizi[0] = '0';
	return (dizi);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s",ft_itoa(-123));
// }

// Parametreden gelen int "n" değerini char dizisine çevirir.