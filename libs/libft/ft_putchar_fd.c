/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:20:38 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/10 18:05:09 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>

// int main()
// {
// 	int fd = open("/Users/sguntepe/Desktop/test.txt",O_WRONLY);
// 	ft_putchar_fd('S',fd);
// }

// Belirtilen dosya tanımlayıcısına (fd) "c" parametresinden gelen
// karakteri yazar.