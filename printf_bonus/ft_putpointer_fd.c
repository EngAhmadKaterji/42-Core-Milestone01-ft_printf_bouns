/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:08:06 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/17 19:09:15 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer_fd(unsigned long long num, int fd)
{
	const char	*hex_digits1;
	int			count;

	hex_digits1 = "0123456789abcdef";
	count = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (num >= 16)
		count += ft_putpointer_fd(num / 16, fd);
	else
	{
		ft_putchar_fd(hex_digits1[num % 16], fd);
		count++;
		return (count);
	}
	ft_putchar_fd(hex_digits1[num % 16], fd);
	count++;
	return (count);
}
