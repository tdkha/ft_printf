/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_output_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 07:50:52 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/16 09:23:22 by ktieu            ###   ########.fr       */
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

t_output_format output_format_init(long long value)
{
	t_output_format	output;

	output.sign = 0;
	output.left = 0;
	output.space = 0;
	output.zero = 0;
	output.hash = 0;
	output.specifier = 0;
	output.value = 0;
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

static int ft_process_num_precision(long long n, char *base, t_flag_format *f, t_output_format *o)
{
	int	count;
	int	num_len;

	count = 0;
	num_len =  ft_num_len(n, *f);
	if (f->left == 1)
	{
		
	}
	if (f->precision > num_len)
	{
		if (f->zero == 1)
			f->zero = 0;
		f->precision - num_len;
		
	}
	return (count);
}

static int	ft_process_num_width(long long n, char *base, t_flag_format *f, t_output_format *o)
{
	int	count;

	count = 0;
	
		
	return (count);
}

void	ft_print_output_num(t_flag_format *f)
{
	
}

int	ft_process_number(long long n, char *base, t_flag_format *f)
{
	t_output_format	output;
	int				count;
	char			*str;

	output = output_format_init(n);
	count = 0;
	str = ft_process_num_precision(n, base, f, &output);
	if (f->precision == 0 && n == 0)
		count += 0;
	else
		count += 100;
	return (count);
}

int	ft_build_number_output(long long n, t_flag_format *f)
{
	static char	*base_ten;
	static char	*base_hex;
	static char	*base_hex_upper;
	
	base_ten = "0123456789";
	base_hex = "0123456789abcde";
	base_hex_upper = "0123456789ABCDE";
	if (f->specifier == 'd' || f->specifier == 'i' || f->specifier == 'u')
	{
		ft_process_number(n, base_ten, f);
	}
	else if (f->specifier == 'x')
	{
		ft_process_number(n, base_hex, f);
	}
	else if (f->specifier == 'X')
	{
		ft_process_number(n, base_hex_upper, f);
	}
}
