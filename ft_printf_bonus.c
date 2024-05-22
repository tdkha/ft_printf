/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:59:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/22 13:51:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_flags(const char *str, va_list ap,
	t_flag_format *flags, int i)
{
	while (str[++i] && ft_isprintformat(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_justify_left_bonus(*flags);
		if (str[i] == '+')
			flags->sign = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_flag_width_star_bonus(ap, *flags);
		if (str[i] == '.')
			i = ft_flag_precision_bonus(str, i, ap, flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit_bonus(str[i], *flags);
		if (ft_isspecifier_bonus(str[i]))
		{
			flags->specifier = str[i];
			break ;
		}
	}
	return (i);
}

static int	ft_parse_format(const char *format, va_list ap, int count, int i)
{
	t_flag_format	flag;
	int				wrote;

	while (format[++i] != '\0')
	{
		flag = ft_flag_init_bonus();
		wrote = 0;
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i = ft_parse_flags(format, ap, &flag, i);
			if (format[i] && flag.specifier > 0 && ft_isprintformat(format[i]))
				wrote = ft_print_format_bonus(flag, ap);
			else if (format[i] != '\0')
				wrote = ft_print_char_bonus(format[i], flag);
		}
		else
		{
			wrote = ft_print_char(format[i]);
		}
		if (wrote == -1)
			return (-1);
		count += wrote;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	i = -1;
	count = 0;
	count = ft_parse_format(format, ap, count, i);
	va_end(ap);
	return (count);
}
