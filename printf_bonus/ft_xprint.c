/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:28:34 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 12:36:29 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xprint(char c, va_list args, t_flag *flags)
{
	unsigned int	numhex;
	int				count;

	count = 0;
	numhex = va_arg(args, unsigned int);
	count = ft_num_hex_digits(numhex);
	if (flags->boolprecision == 1 && flags->precision > flags->zero_padding)
	{
		flags->bzero = '0';
		flags->zero_padding = flags->precision;
	}
	if (flags->hash_flag && numhex != 0)
		count += 2;
	if (flags->left_justify > count)
	{
		ft_insert_hex(c, flags->hash_flag, numhex);
		count += ft_insert_char(' ', flags->left_justify - count);
		return (count);
	}
	else if (flags->zero_padding > count && !flags->left_justify)
		count += ft_insert_char(flags->bzero, flags->zero_padding - count);
	ft_insert_hex(c, flags->hash_flag, numhex);
	return (count);
}
