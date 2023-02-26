/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:14:25 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 13:32:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d",ft_isascii('8'));
// }

// Fonksiyona girilen parametrenin ascii değer aralığında 
// olup olmadığını döndürür. (0 veya 1 şeklinde)