/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_num_base_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:57:11 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/15 14:05:12 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_set_finished(long long *n, int base, t_flag_format *f)
{
	int	len;

	len = numlen(*n, base);
	f->zero = 0;
	f->space = 0;
	f->width = len;
	f->precision = len;
}

static int	ft_pad_zero(long long *n, int base, t_flag_format *f, int has_zero)
{
	int	count;

	count = 0;
	if (*n < 0)
		{
			*n *= -1;
			count += ft_print_char('-');
	}
	count += ft_pad_bonus(f->precision, numlen(*n, base), has_zero);
	return (count);
}

int	ft_process_precision(long long *n, int base, t_flag_format *f, int count)
{
	if (f->precision > numlen(*n, base))
	{
		if(f->left == 1)
		{
			if (f->width > f->precision)
			{
				count += ft_pad_zero(n, base, f, 1);
				f->width -= f->precision - numlen(*n, base);
			}
			else
				count += ft_pad_zero(n, base, f, 1);
		}
		else
		{
			if (f->width > f->precision)
			{
				count+= ft_pad_bonus(f->width - f->precision + numlen(*n, base), numlen(*n, base), 0);
				count += ft_pad_zero(n, base, f, 1);
			}
			else
				count += ft_pad_zero(n, base, f, 1);
			ft_set_finished(n, base, f);
		}
	}
	else
		count = ft_process_width(n, base, f, count);
	return (count);
}

int ft_process_width(long long *n, int base, t_flag_format *f, int count)
{
	int	char_len;

	char_len  = numlen(*n, base);
	
	if (f->left == 0 && f->width > char_len)
	{
		if (f->precision > 0 && char_len > f->precision)
		{
			f->space = 1;
			f->zero = 0;
		}
		if (f->zero == 1)
		{
			count += ft_pad_bonus(f->width, char_len, 1);
		}
		else
		{
			count += ft_pad_bonus(f->width, char_len, 0);
		}
		f->width = char_len; // disable further operation
	}
	return (count);
}

int	ft_process_sign(long long *n, int base, t_flag_format *f, int count)
{
	int	char_len;

	char_len = numlen(*n, base);
	if (f->sign == 0 && *n < 0)
		f->width -= 1;
	if (f->zero == 1)
	{
		f->space = 0;
		if (*n < 0 && f->precision == -1)
		{
			*n *= -1;
			count += ft_print_char('-');
		}
		else if (*n >= 0 && f->sign == 1)
			count += ft_print_char('+');
	}
	else
	{
		if (f->width > char_len)
			f->space = 1;
	}
	return (count);
}
