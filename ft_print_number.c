/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:38:28 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/16 10:44:37 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

typedef struct s_output_format
{
	int			sign;
	int			left;
	int			space;
	int			zero;
	int			hash;
	int			specifier;
	long long	value
}	t_output_format;

t_output_format output_format_init(t_flag_format *f)
{
	t_output_format	output;

	output.sign = f->sign;
	output.left = f->left;
	output.space = 0;
	output.zero = 0;
	output.hash = f->hash;
	output.specifier = f->specifier;
	return (output);
}

int	ft_num_len(long long n, t_flag_format f)
{
	int	len;
	int	base;

	len = 0;
	base = 10;
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		base = 10;
	else if (f.specifier == 'x' || f.specifier == 'X' || f.specifier == 'p')
		base = 16;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_process_num_width(long long n, char *base, t_flag_format *f, t_output_format *o)
{
	int	count;
	int	num_len;

	count = 0;
	num_len = ft_num_len(n, *f);
	if (f->width > num_len)
	{
		if (f->zero == 1)
			o->zero = f->width - num_len;
		else
			o->space = f->width - num_len;
	}
	return (count);
}

static int ft_process_num_precision(long long n, char *base, t_flag_format *f, t_output_format *o)
{
	int	count;
	int	num_len;

	count = 0;
	num_len =  ft_num_len(n, *f);
	if (f->precision > num_len)
	{
		if (f->zero == 1)
			f->zero = 0;
		if (f->precision >= f->width)
			f->width = num_len;
		else
			f->width = (f->width - f->precision) + num_len;
		o->zero = f->precision - num_len;
	}
	return (count);
}

static int ft_process_number(long long n, char *base, t_flag_format *f, t_output_format *o)
{
	int	count;
	
	count = 0;
	if (f->hash == 1)
	{
		f->width -= 3;
	}
	count += ft_process_num_precision(n, base, f, o);
	count += ft_process_num_width(n, base, f, o);
	
	return (count);
}

int	ft_print_output_num(long n, t_output_format *o, t_flag_format *f)
{
	int	len;
	int	num_len;
	int	prefix;

	num_len = ft_num_len(n, *f);
	prefix = 0;
	if (o->specifier)
	len += (o->sign + o->zero + o->space + num_len);
	
	return (len);
}

int	ft_build_number_output(long long n, char *base, t_flag_format *f)
{
	t_output_format	output;
	int				count;
	char			*str;

	output = output_format_init(f);
	count = 0;
	if (f->precision == 0 && n == 0)
		output.zero = f->width;
	else
	{
		count += ft_process_number(n, base, f, &output);
	}
	count += ft_print_output_num(n, &output, f);
	return (count);
}

int	ft_print_number(long long n, t_flag_format *f)
{
	static char	*base_ten;
	static char	*base_hex;
	static char	*base_hex_upper;
	
	base_ten = "0123456789";
	base_hex = "0123456789abcde";
	base_hex_upper = "0123456789ABCDE";
	if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'u')
	{
		ft_build_number_output(n, base_ten, f);
	}
	else if (f->specifier == 'x')
	{
		ft_build_number_output(n, base_hex, f);
	}
	else if (f->specifier == 'X')
	{
		ft_build_number_output(n, base_hex_upper, f);
	}
}
