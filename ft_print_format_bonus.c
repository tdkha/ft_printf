/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:03:56 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/16 18:08:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_format_bonus(t_flag_format f, va_list ap)
{
	int		count;
	char	specifier;

	count = 0;
	specifier = f.specifier;
	if (specifier == 'c')
		count += (ft_print_char_flags_bonus(va_arg(ap, int), f));
	else if (specifier == 's')
		count += (ft_print_str_flags_bonus(va_arg(ap, char *), f));
	else if (specifier == 'p')
		count += (ft_print_ptr_flags_bonus(va_arg(ap, unsigned long), f));
	else if (specifier == 'u')
		count += (ft_print_number(va_arg(ap, unsigned int), &f));
	else if (specifier == 'd' || specifier == 'i')
		count += (ft_print_number(va_arg(ap, int), &f));
	else if (specifier == 'x' || specifier == 'X')
		count += (ft_print_number(va_arg(ap, unsigned int), &f));
	else if (specifier == '%')
		count += (ft_print_char_flags_bonus('%', f));
	else
		return (-1);
	return (count);
}
