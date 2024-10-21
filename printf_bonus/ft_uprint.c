/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:27:36 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 11:48:26 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uprint(va_list args, t_flag *flags)
{
	unsigned int	unum;
	int				count;

	unum = va_arg(args, unsigned int);
	count = ft_unum_digits(unum);
	if (flags->boolprecision == 1 && flags->precision > flags->zero_padding)
	{
		flags->bzero = '0';
		flags->zero_padding = flags->precision;
	}
	if (flags->left_justify > count)
	{
		ft_putunbr_fd(unum, 1);
		count += ft_insert_char(' ', flags->left_justify - count);
		return (count);
	}
	else if (flags->zero_padding > count && !flags->left_justify)
		count += ft_insert_char(flags->bzero, flags->zero_padding - count);
	ft_putunbr_fd (unum, 1);
	return (count);
}
