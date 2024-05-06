/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:52:09 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/06 11:37:29 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_flag_precision_bonus(const char *format, int start,
	va_list ap, t_flag_format *flags)
{
	int	i;

	i = start + 1;
	if (format[i] == '*')
	{
		flags->precision = va_arg(ap, int);
		return (++i);
	}
	flags->precision = 0;
	while (ft_isdigit(format[i]))
	{
		flags->precision = (flags->precision * 10) + (format[i] - '0');
		i++;
	}
	return (i);
}
