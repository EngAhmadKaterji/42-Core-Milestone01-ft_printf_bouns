/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:41:46 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/17 19:24:55 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_insert_char(char c, int len)
{
	int	count;

	count = 0;
	if (len <= 0)
		return (count);
	while (len)
	{
		ft_putchar_fd(c, 1);
		count++;
		len--;
	}
	return (count);
}
