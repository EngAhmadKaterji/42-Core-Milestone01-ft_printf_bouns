/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:59:00 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 10:22:20 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_zero_flags(void)
{
	t_flag	*flags;

	flags = malloc(sizeof(t_flag));
	if (flags == NULL)
		return (NULL);
	flags->hash_flag = 0;
	flags->left_justify = 0;
	flags->plus_flag = 0;
	flags->precision = 0;
	flags->boolprecision = 0;
	flags->space_flag = 0;
	flags->zero_padding = 0;
	flags->bzero = ' ';
	return (flags);
}

const char	*ft_check(const char *str, va_list args, int *count)
{
	t_flag	*flags;

	*count = 0;
	flags = ft_zero_flags();
	str = ft_parse_flags(str, flags);
	if (*str == 's')
		*count = ft_sprint (args, flags);
	else if (*str == 'd' || *str == 'i')
		*count = ft_diprint(args, flags);
	else if (*str == 'c')
		*count = ft_cprint(args, flags);
	else if (*str == 'p')
		*count = ft_pprint(args, flags);
	else if (*str == 'u')
		*count = ft_uprint(args, flags);
	else if (*str == 'x' || *str == 'X')
		*count = ft_xprint(*str, args, flags);
	else if (*str == '%')
		*count = ft_percentprint();
	free (flags);
	return (str);
}
