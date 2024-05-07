/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:22:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/07 08:18:42 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	fr_print_str_precision(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

static int	ft_print_string(char *str, t_flag_format flags)
{
	int	count;

	count = 0;
	if (flags.precision > 0)
	{
		count += ft_padding_bonus(flags.precision, ft_strlen(str), 0);
		count += fr_print_str_precision(str, flags.precision);
	}
	else
		count += fr_print_str_precision(str, ft_strlen(str));
	return (count);
}

int	ft_print_str_flags_bonus(char *str, t_flag_format flags)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		flags.precision = ft_strlen(str);
	}
	if (flags.precision >= 0 && flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_print_string(str, flags);
	if (flags.precision >= 0)
		count += ft_padding_bonus(flags.width, flags.precision, 0);
	else
		count += ft_padding_bonus(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_print_string(str, flags);
	return (count);
}

	// printf("-----------------------------------\n");
	// printf("Left: %d\n", flags.left);
	// printf("Width: %d\n", flags.width);
	// printf("Precesion: %d\n", flags.precision);
	// printf("-----------------------------------\n");