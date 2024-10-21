/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:58:04 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/17 19:05:33 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_insert_pointer(int flags_hash_flag,
	unsigned long long numhex)
{
	if (flags_hash_flag)
		ft_putstr_fd("0x", 1);
	ft_putpointer_fd(numhex, 1);
}

int	ft_num_hex_pointer(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd, t_flag *flags)
{
	unsigned long long	address;
	int					count;

	count = 2;
	address = (unsigned long long)ptr;
	printf("we are here %lld\n",address);
	if (!address)
	{
		ft_putstr_fd ("(nil)", fd);
		return (5);
	}
	count += ft_num_hex_pointer(address);
	if (flags->left_justify > count)
	{
		ft_insert_pointer(1, address);
		count += ft_insert_char(' ', flags->left_justify - count);
		return (count);
	}
	else if (flags->zero_padding > count && !flags->left_justify)
		count += ft_insert_char('0', flags->left_justify - count);
	ft_insert_pointer(1, address);
	return (count);
}
