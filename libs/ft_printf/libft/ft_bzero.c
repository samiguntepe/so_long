/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:08:53 by sguntepe          #+#    #+#             */
/*   Updated: 2023/03/07 16:54:23 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i;
// 	char str[] = "samiguntepe";
// 	i = ft_strlen(str);
// 	ft_bzero(str, 4);
// 	write(1,&str,i);
// 	return 0;
// }

// Parametreden gelen "s" dizisine n kadar null değer atar.