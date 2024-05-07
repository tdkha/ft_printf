/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:03:56 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/07 07:59:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_format_specifier(t_flag_format flags, va_list ap,
	char *lower_base, char *upper_base)
{
	char	specifier;

	specifier = flags.specifier;
	if (specifier == 'c')
		return (ft_print_char_flags_bonus(va_arg(ap, int), flags));
	else if (specifier == 's')
		return (ft_print_str_flags_bonus(va_arg(ap, char *), flags));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long)));
	else if (specifier == 'u')
		return (ft_print_num_base(va_arg(ap, unsigned int), 10, lower_base));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num_base(va_arg(ap, int), 10, lower_base));
	else if (specifier == 'x')
		return (ft_print_num_base(va_arg(ap, unsigned int), 16, lower_base));
	else if (specifier == 'X')
		return (ft_print_num_base(va_arg(ap, unsigned int), 16, upper_base));
	else if (specifier == '%')
		return (ft_check_write_return_count('%'));
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
