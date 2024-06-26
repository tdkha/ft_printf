/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:45:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/22 12:54:03 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_num_len_flag(long long n, t_flag_format f)
{
	int	len;
	int	base;

	len = 0;
	base = 10;
	if (n == 0 && f.precision == 0)
		return (0);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		base = 10;
	else if (f.specifier == 'x' || f.specifier == 'X' || f.specifier == 'p')
		base = 16;
	if (n < 0)
	{
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_num_len_base_output(long long n, int base, t_output_format o)
{
	int	len;

	len = 0;
	if (o.no_value == 1)
		return (0);
	if (n < 0)
	{
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

#ifdef __APPLE__

int	ft_ptr_len_flag(unsigned long n)
{
	char	*ptr_null;
	int		len;
	int		base;

	ptr_null = "0x0";
	len = 0;
	base = 16;
	if (n == 0)
		return (ft_strlen(ptr_null));
	while (n > 0)
	{
		n /= base;
		len++;
	}
	len += 2;
	return (len);
}

#else

int	ft_ptr_len_flag(unsigned long n)
{
	char	*ptr_null;
	int		len;
	int		base;

	ptr_null = "(nil)";
	len = 0;
	base = 16;
	if (n == 0)
		return (ft_strlen(ptr_null));
	while (n > 0)
	{
		n /= base;
		len++;
	}
	len += 2;
	return (len);
}

#endif