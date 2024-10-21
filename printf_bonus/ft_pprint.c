/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:26:45 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/16 20:05:16 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pprint(va_list args, t_flag *flags)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	count = ft_putptr_fd(ptr, 1, flags);
	return (count);
}
