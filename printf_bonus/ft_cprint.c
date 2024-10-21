/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:45 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/17 09:44:59 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cprint(va_list args, t_flag *flags)
{
	char	c;
	int		count;

	c = va_arg(args, int);
	count = 1;
	if (flags->left_justify > 1)
	{
		ft_putchar_fd(c, 1);
		count += ft_insert_char(' ', flags->left_justify - 1);
	}
	else if (flags->zero_padding > 1)
	{
		count += ft_insert_char(' ', flags->zero_padding - 1);
		ft_putchar_fd(c, 1);
	}
	else
		ft_putchar_fd (c, 1);
	return (count);
}
