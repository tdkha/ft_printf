/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:03:56 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/23 10:01:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

#ifdef __APPLE__

int	ft_print_format_bonus(t_flag_format f, va_list ap)
{
	char	specifier;

	specifier = f.specifier;
	if (specifier == 'c')
		return (ft_print_char_bonus(va_arg(ap, int), f));
	else if (specifier == 's')
		return (ft_print_str_bonus(va_arg(ap, char *), f));
	else if (specifier == 'p')
		return (ft_print_ptr_bonus(va_arg(ap, unsigned long), f));
	else if (specifier == 'u')
		return (ft_print_num_base_bonus(va_arg(ap, unsigned int), &f));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num_base_bonus(va_arg(ap, int), &f));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_num_base_bonus(va_arg(ap, unsigned int), &f));
	else if (specifier == '%')
		return (ft_print_char_bonus('%', f));
	else
		return (-1);
}

#else

int	ft_print_format_bonus(t_flag_format f, va_list ap)
{
	char	specifier;

	specifier = f.specifier;
	if (specifier == 'c')
		return (ft_print_char_bonus(va_arg(ap, int), f));
	else if (specifier == 's')
		return (ft_print_str_bonus(va_arg(ap, char *), f));
	else if (specifier == 'p')
		return (ft_print_ptr_bonus(va_arg(ap, unsigned long), f));
	else if (specifier == 'u')
		return (ft_print_num_base_bonus(va_arg(ap, unsigned int), &f));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num_base_bonus(va_arg(ap, int), &f));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_num_base_bonus(va_arg(ap, unsigned int), &f));
	else if (specifier == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}

#endif