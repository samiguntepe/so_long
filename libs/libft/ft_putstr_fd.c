/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:20:49 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/10 18:07:53 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

//#include <fcntl.h>

// int main()
// {
//     int fd= open("/Users/sguntepe/Desktop/test.txt",1);
//     ft_putstr_fd("Merhaba 42 Kocaeli",fd);
// }

// Belirtilen dosya tanımlayıcısına (fd) "s" parametresinden gelen
// char dizisi yazılır.