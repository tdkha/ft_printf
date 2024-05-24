/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:33:02 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/24 14:15:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_process_ptr_precision(
	unsigned long ptr,
	int num_len,
	t_flag_format *f,
	t_output_format *o
)
{
	if (ptr == 0 && f->precision > 1)
	{
		o->right_zeros = f->precision - 1;
	}
	if (ptr != 0 && f->precision > 1 
		&& f->precision > (num_len - 2))
	{
		o->left_zeros = f->precision - (num_len) + 2;
	}
}

static void	ft_process_ptr(
	unsigned long ptr,
	int num_len,
	t_flag_format *f,
	t_output_format *o
)
{
	ft_process_ptr_precision(ptr, num_len, f, o);
	if (f->zero == 1)
	{
		f->zero = 0;
		f->space = 1;
	}
	if (f->precision != -1)
	{
		f->precision = num_len;
	}
	if (f->width > num_len)
	{
		if (f->left == 1)
			o->right_spaces = f->width - (num_len);
		else
			o->left_spaces = f->width - (num_len);
	}
}

static int	ft_process_print_ptr(
	unsigned long ptr,
	int num_len,
	t_flag_format *f
	)
{
	int				len;
	t_output_format	o;

	len = 0;
	o = ft_output_format_init(f);
	ft_process_ptr(ptr, num_len, f, &o);
	len = ft_print_output_ptr(ptr, num_len, &o);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_print_ptr_bonus(unsigned long ptr, t_flag_format flags)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_ptr_len_flag(ptr, &flags);
	len = ft_process_print_ptr(ptr, num_len, &flags);
	if (len == -1)
		return (-1);
	return (len);
}
