/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:59:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/15 15:43:24 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	numlen(long long n, int base)
{
	int	len;

	len = 0;
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

static int	ft_pre_process(
	long long *n,
	int base,
	t_flag_format *f,
	int count
	)
{
	if (f->hash == 1 && base == 16)
		f->width -= 3;
	count = ft_process_sign(n, base, f, count);
	count = ft_process_precision(n, base, f, count);
	if (f->sign == 1 && *n >= 0)
		count += ft_check_write_return_count((int) '+');
	return (count);
}

static int	ft_post_process(long long *n, int base, t_flag_format *flags)
{
	int	count;
	int	len;

	count = 0;
	len = numlen(*n, base);
	if (flags->width > len)
	{
		if (flags->zero)
		{
			count += ft_pad_bonus(flags->width, numlen(*n, base), 1);
		}
		else
		{
			count += ft_pad_bonus(flags->width, numlen(*n, base), 0);
		}
	}
	return (count);
}

int	ft_print_num_base_bonus(
	long long n,
	int base,
	char *lst_base,
	t_flag_format flags)
{
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
		return (count + ft_pad_bonus(flags.width, 0, 0));
	count += ft_pre_process(&n, base, &flags, 0);
	count += ft_print_num_base(n, base, lst_base);
	count += ft_post_process(&n, base, &flags);
	return (count);
}
// printf("-----------------------------------\n");
	// printf("Left: %d\n", flags->left);
	// printf("Space: %d\n", flags->space);
	// printf("Zero: %d\n", flags->zero);
	// printf("Sign: %d\n", flags->sign);
	// printf("Width: %d\n", flags->width);
	// printf("precision: %d\n", flags->precision);
	// printf("len: %d\n", numlen(*n, base));
	// printf("Number: %lld\n", *n);
	// printf("-----------------------------------\n");

		// printf("-----------------------------------\n");
	// printf("Left: %d\n", flags->left);
	// printf("Space: %d\n", flags->space);
	// printf("Zero: %d\n", flags->zero);
	// printf("Sign: %d\n", flags->sign);
	// printf("Width: %d\n", flags->width);
	// printf("precision: %d\n", flags->precision);
	// printf("len: %d\n", numlen(*n, base));
	// printf("Number: %lld\n", *n);
	// printf("-----------------------------------\n");