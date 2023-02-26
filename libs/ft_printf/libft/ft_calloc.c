/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:19:15 by sguntepe          #+#    #+#             */
/*   Updated: 2023/01/01 13:26:51 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// Her birinin boyutu byte olarak ifade edilen ve size parametre değeri kadar
// olan bellekten count parametre değeri kadar sayıda bellek bloğunu tahsis eder
// ve tahsis edilen belleğin tamamını sıfır değeri ile doldurur.
// Malloc fonksiyonu ile bellekte alan açıp 
// ft_bzero fonksiyonu ile null atayarak döndürüyoruz.