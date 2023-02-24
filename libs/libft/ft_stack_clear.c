/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:38:24 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/09 15:22:14 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = ft_stack_pop(stack);
		free(tmp);
	}
}
