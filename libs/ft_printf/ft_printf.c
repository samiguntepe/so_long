/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:30:46 by sguntepe          #+#    #+#             */
/*   Updated: 2022/12/08 15:11:22 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_format(va_list arg, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((arg), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((arg), int)));
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((arg), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((arg), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((arg), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((arg), char *)));
	else
		return (ft_string("%"));
}

bool	ft_flag_catch(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		rtn;

	i = -1;
	rtn = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (ft_flag_catch(str, i))
			rtn += ft_format(arg, str[++i]);
		else
		{
			if (str[i] == '%')
				return (0);
			rtn += write(1, &str[i], 1);
		}	
	}
	va_end(arg);
	return (rtn);
}
