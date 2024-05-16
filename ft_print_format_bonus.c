/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:03:56 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/16 10:38:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_format_specifier(t_flag_format f, va_list ap,
	char *l, char *u)
{
	char	specifier;

	specifier = f.specifier;
	if (specifier == 'c')
		return (ft_print_char_flags_bonus(va_arg(ap, int), f));
	else if (specifier == 's')
		return (ft_print_str_flags_bonus(va_arg(ap, char *), f));
	else if (specifier == 'p')
		return (ft_print_ptr_flags_bonus(va_arg(ap, unsigned long), f));
	else if (specifier == 'u')
		return (ft_print_number(va_arg(ap, unsigned int), 10, l, f));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(ap, int), 10, l, f));
	else if (specifier == 'x')
		return (ft_print_number(va_arg(ap, unsigned int), 16, l, f));
	else if (specifier == 'X')
		return (ft_print_number(va_arg(ap, unsigned int), 16, u, f));
	else if (specifier == '%')
		return (ft_print_char_flags_bonus('%', f));
	else
		return (-1);
}

int	ft_print_format_bonus(t_flag_format flags, va_list ap)
{
	int		count;
	char	*upper_base;
	char	*lower_base;

	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
	count = ft_parse_format_specifier(flags, ap, lower_base, upper_base);
	return (count);
}
