/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:22:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/13 23:32:08 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_print_s_pre(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

static int	ft_print_string(char *str, t_flag_format flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_padding_bonus(flags.precision, ft_strlen(str), 0);
		count += ft_print_s_pre(str, flags.precision);
	}
	else
		count += ft_print_s_pre(str, ft_strlen(str));
	return (count);
}



#if defined(__linux__) || defined(__gnu_linux__)

int	ft_print_str_flags_bonus(char *str, t_flag_format flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		count += ft_padding_bonus(flags.width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
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

#else

int	ft_print_str_flags_bonus(char *str, t_flag_format flags)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
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
#endif
