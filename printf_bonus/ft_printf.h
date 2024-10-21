/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:20:55 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/18 10:21:46 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_flag
{
	char	bzero;
	int		plus_flag;
	int		zero_padding;
	int		hash_flag;
	int		space_flag;
	int		precision;
	int		boolprecision;
	int		left_justify;
}	t_flag;
const char	*ft_check(const char *str, va_list args, int *check_flags);
char		*ft_parse_flags(const char *format, t_flag *flags);
int			ft_printf(const char *str, ...);
int			ft_xprint(char c, va_list args, t_flag *flags);
int			ft_uprint(va_list args, t_flag *flags);
int			ft_sprint(va_list args, t_flag *flags);
int			ft_putunbr_fd(unsigned int n, int fd);
int			ft_putptr_fd(void *ptr, int fd, t_flag *flags);
int			ft_puthex_fd(unsigned int num, int index, int fd);
int			ft_pprint(va_list args, t_flag *flags);
int			ft_percentprint(void);
int			ft_parse(const char *str, va_list args, char *set);
int			ft_num_hex_digits(unsigned int n);
int			ft_num_digits(int n);
int			ft_diprint(va_list args, t_flag *flags);
int			ft_cprint(va_list args, t_flag *flags);
int			ft_unum_digits(unsigned int unum);
int			ft_sprintnull(void);
int			ft_putstr(char *s, int flags_precision, int fd);
int			ft_insert_char(char c, int len);
int			ft_putpointer_fd(unsigned long long num, int fd);
void		ft_insert_hex(char c, int flags_hash_flag, int numhex);
t_flag		*ft_zero_flags(void);

#endif