/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:59:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/12 17:24:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_flags(const char *str, va_list ap,
	t_flag_format *flags, int i)
{
	while (str[++i] && ft_isprintformat_bonus(str[i]))
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

static int	ft_parse_format(const char *format, va_list ap)
{
	int				i;
	t_flag_format	flag_format;
	int				count;

	i = -1;
	count = 0;
	while (format[++i] != '\0')
	{
		flag_format = ft_flag_init_bonus();
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i = ft_parse_flags(format, ap, &flag_format, i);
			if (format[i] && flag_format.specifier > 0
				&& ft_isprintformat_bonus(format[i]))
				count += ft_print_format_bonus(flag_format, ap);
			else if (format[i] != '\0')
				count += ft_print_char_flags_bonus(format[i], flag_format);
		}
		else
			count += ft_print_char(format[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	count = ft_parse_format(format, ap);
	va_end(ap);
	return (count);
}

// printf("--------------FLAGS--------------\n");
	// printf("Specifier: %d\n", flags->specifier);
	// printf("Left justiry: %d\n", flags->left);
	// printf("With: %d\n", flags->width);
	// printf("--------------FLAGS--------------\n");