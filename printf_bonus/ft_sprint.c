/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:25:51 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 09:58:48 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_one(char *arg, int flags_left_justify)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < flags_left_justify)
	{
		if (*arg != '\0')
		{
			ft_putchar_fd(*arg, 1);
			arg++;
		}
		else
			ft_putchar_fd(' ', 1);
		count++;
		i++;
	}
	return (count);
}

int	ft_two(char *arg, int flags_left_justify, int flags_precision)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < flags_left_justify)
	{
		if (*arg != '\0' && i < flags_precision)
			ft_putchar_fd(*arg, 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
		arg++;
		i++;
	}
	return (count);
}

int	ft_three(char *arg, int flags_zero_padding, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < flags_zero_padding)
	{
		if (flags_zero_padding - len)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
		else if (*arg != '\0')
		{
			ft_putchar_fd(*arg, 1);
			arg++;
		}
		count++;
		i++;
	}
	return (count);
}

int	ft_four(char *arg, int flags_zero_padding, int len)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < flags_zero_padding)
	{
		if (flags_zero_padding - len)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
		else if (*arg != '\0')
		{
			ft_putchar_fd(*arg, 1);
			arg++;
		}
		count++;
		i++;
	}
	return (count);
}

int	ft_sprint(va_list args, t_flag *flags)
{
	char	*arg;
	int		len;

	arg = va_arg(args, char *);
	if (arg == NULL)
		return (ft_sprintnull());
	len = ft_strlen(arg);
	if (!flags->precision && !flags->boolprecision
		&& len >= flags->left_justify && len >= flags->zero_padding)
		return (ft_putstr (arg, flags->precision, 1));
	else if (flags->precision && len >= flags->left_justify
		&& len >= flags->zero_padding)
		return (ft_putstr(arg, flags->precision, 1));
	else if (!flags->precision && len < flags->left_justify)
		return (ft_one(arg, flags->left_justify));
	else if (flags->precision && len < flags->left_justify)
		return (ft_two(arg, flags->left_justify, flags->precision));
	else if (!flags->precision && len < flags->zero_padding)
		return (ft_three(arg, flags->zero_padding, len));
	else if (flags->precision && len < flags->zero_padding)
		return (ft_four(arg, flags->zero_padding, flags->precision));
	return (0);
}
