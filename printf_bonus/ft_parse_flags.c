/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:24:35 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 10:21:55 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_left_justify(char *tmp, t_flag *flags)
{
	while (*tmp == '-')
		tmp++;
	flags->left_justify = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	return (tmp);
}

char	*ft_parse_zero_padding(char *tmp, t_flag *flags)
{
	if (*tmp == '0')
		flags->bzero = '0';
	while (*tmp == '0')
		tmp++;
	flags->zero_padding = ft_atoi(tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	return (tmp);
}

char	*ft_parse_percision(char *tmp, t_flag *flags)
{
	flags->boolprecision = 1;
	flags->precision = ft_atoi(++tmp);
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
	return (tmp);
}

char	*ft_insert_flags(char *tmp, t_flag *flags)
{
	if (*tmp == '-')
		tmp = ft_parse_left_justify(tmp, flags);
	else if (*tmp >= '0' && *tmp <= '9')
		tmp = ft_parse_zero_padding(tmp, flags);
	else if (*tmp == '#')
	{
		flags->hash_flag = 1;
		tmp++;
	}
	else if (*tmp == '+')
	{
		flags->plus_flag = 1;
		flags->space_flag = 0;
		tmp++;
	}
	else if (*tmp == ' ')
	{
		if (!flags->plus_flag)
			flags->space_flag = 1;
		tmp++;
	}
	else if (*tmp == '.')
		tmp = ft_parse_percision(tmp, flags);
	return (tmp);
}

char	*ft_parse_flags(const char *format, t_flag *flags)
{
	char	*tmp;

	tmp = (char *)format;
	while (*tmp == '-' || *tmp == '0' || *tmp == '#' || *tmp == '+'
		|| *tmp == ' ' || *tmp == '.' || (*tmp >= '1' && *tmp <= '9'))
		tmp = ft_insert_flags(tmp, flags);
	return (tmp);
}
