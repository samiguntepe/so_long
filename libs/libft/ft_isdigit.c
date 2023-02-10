/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:43:41 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 13:35:09 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d",ft_isdigit('8'));
// }

// Fonksiyona girilen parametrenin rakam 
// olup olmadığını döndürür.(0 veya 1 şeklinde)