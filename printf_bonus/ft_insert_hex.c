/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:47:00 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 12:37:40 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_insert_hex(char c, int flags_hash_flag, int numhex)
{
	if (c == 'x')
	{
		if (flags_hash_flag && numhex != 0)
			ft_putstr_fd("0x", 1);
		ft_puthex_fd(numhex, 0, 1);
	}
	else if (c == 'X')
	{
		if (flags_hash_flag && numhex != 0)
			ft_putstr_fd("0X", 1);
		ft_puthex_fd(numhex, 1, 1);
	}
}
