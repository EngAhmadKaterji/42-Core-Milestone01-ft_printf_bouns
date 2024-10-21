/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:23:30 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 12:01:12 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_insert_negative(t_flag *flags, int num, int count)
{
	if (flags->space_flag && !flags->plus_flag
		&& !flags->left_justify && num >= 0)
		count += ft_insert_char (' ', flags->space_flag);
	if (flags->plus_flag && num >= 0)
		count += ft_insert_char('+', flags->plus_flag);
	if (flags->zero_padding && !flags->left_justify)
	{
		if (num >= 0)
			count += ft_insert_char(flags->bzero, flags->zero_padding - count);
		else if (num == -2147483648)
		{
			ft_putchar_fd ('-', 1);
			count += ft_insert_char(flags->bzero, flags->zero_padding - count);
			ft_putchar_fd ('2', 1);
			num = 147483648;
		}
		else if (num < 0)
		{
			ft_putchar_fd('-', 1);
			count += ft_insert_char(flags->bzero, flags->zero_padding - count);
			num = -1 * num;
		}
	}
	ft_putnbr_fd(num, 1);
	return (count);
}

int	ft_diprint(va_list args, t_flag *flags)
{
	int	count;
	int	num;

	count = 0;
	num = va_arg(args, int);
	count = ft_num_digits(num);
	if (flags->boolprecision == 1 && flags->precision > flags->zero_padding)
	{
		flags->bzero = '0';
		flags->zero_padding = flags->precision;
		if (num < 0)
			flags->zero_padding++;
	}
	if (flags->left_justify > count)
	{
		if (flags->plus_flag && num >= 0)
			count += ft_insert_char('+', flags->plus_flag);
		ft_putnbr_fd(num, 1);
		count += ft_insert_char(' ', flags->left_justify - count);
		return (count);
	}
	else
		count = ft_insert_negative(flags, num, count);
	return (count);
}
