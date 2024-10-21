/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:40 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/19 11:10:01 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;
	char	set[10];

	ft_strlcpy (set, "cspdiuxX%", sizeof(set));
	if (!format || *format == '\0')
		return (-1);
	str = ft_strdup(format);
	if (!str)
		return (-1);
	count = 0;
	va_start(args, format);
	count = ft_parse(str, args, set);
	va_end(args);
	free(str);
	return (count);
}

int main()
{
	ft_printf("%p\n",NULL);
	return 0;
}