/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:00:31 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/17 13:38:29 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *str, va_list args, char *set)
{
	int	count;
	int	check_flags;

	count = 0;
	check_flags = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str = ft_check(++str, args, &check_flags);
			if (!check_flags && !is_char(*str, set))
			{
				ft_putchar_fd(*str, 1);
				count++;
			}
			count += check_flags;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
