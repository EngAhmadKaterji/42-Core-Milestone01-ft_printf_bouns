/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:26:40 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 09:49:00 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int flags_precision, int fd)
{
	int	i;

	i = 0;
	if (!flags_precision)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
	{
		while (s[i] != '\0' && i < flags_precision)
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}
