/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:34:18 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/18 19:48:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_process_num_width(
	int num_len,
	t_flag_format *f,
	t_output_format *o)
{
	int	count;

	count = 0;
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
				o->left_spaces = f->width - num_len;
		}
	}
	if (f->width == 0 && f->space == 1)
		o->left_spaces = 1;
	return (count);
}

static int	ft_process_num_precision(
	long long n,
	t_flag_format *f,
	t_output_format *o)
{
	int	count;
	int	ft_num_len;

	count = 0;
	ft_num_len = ft_num_len_flag(n, *f);
	if (f->precision > ft_num_len)
	{
		if (f->zero == 1)
			f->zero = 0;
		if (f->precision >= f->width)
			f->width = ft_num_len;
		else
			f->width = (f->width - f->precision) + ft_num_len;
		o->left_zeros = f->precision - ft_num_len;
	}
	else
	{
		if (f->precision > 0 && f->precision < f->width)
		{
			f->zero = 0;
			f->space = 1;
		}
	}
	return (count);
}

static int	ft_process_number(
	long long n,
	t_flag_format *f,
	t_output_format *o)
{
	int	count;
	int	num_len;

	count = 0;
	num_len = ft_num_len_flag(n, *f);
	if (f->hash == 1)
	{
		f->width -= 2;
	}
	count += ft_process_num_precision(n, f, o);
	if (n < 0 || f->sign == 1)
		f->width--;
	count += ft_process_num_width(num_len, f, o);
	return (count);
}

int	ft_build_number_output(long long n, char *base, t_flag_format *f)
{
	t_output_format	output;
	int				count;

	output = output_format_init(f);
	count = 0;
	if (f->precision == 0 && n == 0)
		return (count);
	else
	{
		count += ft_process_number(n, f, &output);
	}
	count += ft_print_output_num(n, &output, f, base);
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
		count += ft_build_number_output(n, base_ten, f);
	}
	else if (f->specifier == 'x')
	{
		count += ft_build_number_output(n, base_hex, f);
	}
	else if (f->specifier == 'X')
	{
		count += ft_build_number_output(n, base_hex_upper, f);
	}
	return (count);
}

// printf("---------------------------------\n");
	// printf("Sign: %d\n", o->sign);
	// printf("Left: %d\n", o->left);
	// printf("Hash: %d\n", o->hash);
	// printf("Left Space: %d\n", o->left_spaces);
	// printf("Right Space: %d\n", o->right_spaces);
	// printf("Left Zero: %d\n", o->left_zeros);
	// printf("Right Zero: %d\n", o->right_zeros);
	// printf("Specifier:: %c\n", o->specifier);
	// printf("---------------------------------\n");