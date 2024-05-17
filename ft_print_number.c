/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:38:28 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/17 07:50:19 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

typedef struct s_output_format
{
	int			sign;
	int			left;
	int			hash;
	int			left_zeros;
	int			right_zeros;
	int			left_spaces;
	int			right_spaces;
	int			specifier;
}	t_output_format;

t_output_format output_format_init(t_flag_format *f)
{
	t_output_format	output;

	output.sign = f->sign;
	output.left = f->left;
	output.hash = f->hash;
	output.left_zeros = 0;
	output.right_zeros = 0;
	output.left_spaces = 0;
	output.right_spaces = 0;
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

static int	ft_process_num_width(long long n, t_flag_format *f, t_output_format *o)
{
	int	count;
	int	num_len;

	count = 0;
	num_len = ft_num_len(n, *f);
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
	return (count);
}

static int ft_process_num_precision(long long n, t_flag_format *f, t_output_format *o)
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
		o->left_zeros = f->precision - num_len;
	}
	return (count);
}

static int ft_process_number(long long n, t_flag_format *f, t_output_format *o)
{
	int	count;
	
	count = 0;
	if (f->hash == 1)
	{
		f->width -= 3;
	}
	count += ft_process_num_precision(n, f, o);
	count += ft_process_num_width(n, f, o);
	
	return (count);
}

int	ft_print_output_num(long n, t_output_format *o, t_flag_format *f)
{
	int	len;
	int	num_len;
	int total_zeros;
	int	total_spaces;

	len = 0;
	num_len = ft_num_len(n, *f);
	total_zeros = o->left_zeros + o->right_zeros;
	total_spaces = o->left_spaces + o->right_spaces;
	len += (o->sign + total_zeros + total_spaces + num_len);
	printf("---------------------------------\n");
	printf("Sign: %d\n", o->sign);
	printf("Left: %d\n", o->left);
	printf("Hash: %d\n", o->hash);
	printf("Left Space: %d\n", o->left_spaces);
	printf("Right Space: %d\n", o->right_spaces);
	printf("Left Zero: %d\n", o->left_zeros);
	printf("Right Zero: %d\n", o->right_zeros);
	printf("Specifier:: %c\n", o->specifier);
	printf("---------------------------------\n");

	if (o->left == 1)
	{
		// add zero
		// add number
		// add space
	}
	else
	{
		// add space
		// add zero
		// add value
	}
	return (len);
}

int	ft_build_number_output(long long n, char *base, t_flag_format *f)
{
	t_output_format	output;
	int				count;

	base = base;

	
	output = output_format_init(f);
	count = 0;
	
	if (f->precision == 0 && n == 0)
		output.left_zeros = f->width;
	else
	{
		count += ft_process_number(n, f, &output);
	}
	count += ft_print_output_num(n, &output, f);
	return (count);
}

int	ft_print_number(long long n, t_flag_format *f)
{
	int 		count;
	static char	*base_ten;
	static char	*base_hex;
	static char	*base_hex_upper;
	
	count = 0;
	base_ten = "0123456789";
	base_hex = "0123456789abcde";
	base_hex_upper = "0123456789ABCDE";
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
