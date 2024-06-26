/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:18 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/23 10:42:06 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_process_num_width(
	int num_len,
	t_flag_format *f,
	t_output_format *o)
{
	if (f->width > num_len)
	{
		if (f->zero == 1)
		{
			if (f->left == 1)
				o->right_zeros = f->width - num_len;
			else
				o->left_zeros = f->width - num_len;
		}
		else
		{
			if (f->left == 1)
				o->right_spaces = f->width - num_len;
			else
				o->left_spaces += f->width - num_len;
		}
	}
}

static void	ft_process_num_precision(
	long long n,
	t_flag_format *f,
	t_output_format *o)
{
	int	num_len;

	num_len = ft_num_len_flag(n, *f);
	if (f->precision > num_len)
	{
		if (f->zero == 1)
			f->zero = 0;
		if (f->precision >= f->width)
			f->width = num_len;
		else
			f->width = (f->width - f->precision) + num_len;
		if (f->space == 1 && n >= 0)
			o->left_spaces = 1;
		o->left_zeros = f->precision - num_len;
	}
	else
	{
		if (f->precision >= 0 && f->precision < f->width)
		{
			f->zero = 0;
			f->space = 1;
		}
	}
}

static void	ft_process_number(
	long long n,
	t_flag_format *f,
	t_output_format *o)
{
	int	num_len;

	num_len = ft_num_len_flag(n, *f);
	if (f->hash == 1 && n != 0)
	{
		f->width -= 2;
	}
	if (f->space == 1)
	{
		if (f->sign == 1 || n < 0)
			f->space = 0;
		else
		{
			o->left_spaces = 1;
			f->width--;
		}
	}
	ft_process_num_precision(n, f, o);
	if (f->width <= 0 && f->space == 1)
		o->left_spaces = 1;
	if (n < 0 || f->sign == 1)
		f->width--;
	ft_process_num_width(num_len, f, o);
}

int	ft_process_print_num_base(long long n, char *base, t_flag_format *f)
{
	t_output_format	output;
	int				count;

	output = ft_output_format_init(f);
	count = 0;
	ft_process_number(n, f, &output);
	count = ft_print_output_num(n, &output, f, base);
	return (count);
}

int	ft_print_num_base_bonus(long long n, t_flag_format *f)
{
	int			count;
	static char	*base_ten;
	static char	*base_hex;
	static char	*base_hex_upper;

	count = 0;
	base_ten = "0123456789";
	base_hex = "0123456789abcdef";
	base_hex_upper = "0123456789ABCDEF";
	if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'u')
	{
		count += ft_process_print_num_base(n, base_ten, f);
	}
	else if (f->specifier == 'x')
	{
		count += ft_process_print_num_base(n, base_hex, f);
	}
	else if (f->specifier == 'X')
	{
		count += ft_process_print_num_base(n, base_hex_upper, f);
	}
	return (count);
}
