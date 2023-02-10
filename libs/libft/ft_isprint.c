/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:15:32 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 13:37:34 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d",ft_isprint('\0'));
// }

// Fonksiyona girilen parametrenin ekrana
// yazılıp yazılmadığını döndürür.(0 veya 1 şeklinde)