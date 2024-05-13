/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:59:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/13 23:53:20 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_len(long long n, int base)
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

static int	ft_pre_process_extent(
	long long *n,
	int base,
	t_flag_format *flags,
	int count)
{
	if (flags->width > ft_num_len(*n, base) && flags->zero == 0)
		flags->space = 1;
	if (flags->left == 0 && flags->zero == 1)
		count += ft_padding_bonus(
				flags->width,
				ft_num_len(*n, base) + flags->sign,
				1);
	else if (flags->left == 0 && flags->space == 1)
		count += ft_padding_bonus(
				flags->width,
				ft_num_len(*n, base) + flags->sign,
				0);
	if ((flags->left == 0 && (flags->zero == 1 || flags->space == 1)))
		flags->width = ft_num_len(*n, base) + flags->sign;
	return (count);
}

static int	ft_pre_process(
	long long *n,
	int base,
	t_flag_format *flags,
	int count)
{
	if (flags->precision > ft_num_len(*n, base))
	{
		flags->width = flags->precision;
		flags->zero = 1;
	}
	if (flags->sign == 1 || *n < 0)
		flags->width -= 1;
	if (flags->zero == 1)
	{
		flags->space = 0;
		if (*n < 0)
		{
			*n *= -1;
			count += ft_print_char('-');
		}
		else
			count += ft_print_char('+');
	}
	count += ft_pre_process_extent(n, base, flags, count);
	if (flags->sign == 1 && *n >= 0)
		ft_check_write_return_count((int) '+');
	return (count);
}

static int	ft_post_process(long long *n, int base, t_flag_format *flags)
{
	int	count;
	int	len;

	count = 0;
	len = ft_num_len(*n, base);
	if (flags->width >= len)
	{
		if (flags->zero)
			count += ft_padding_bonus(flags->width, ft_num_len(*n, base), 1);
		else
			count += ft_padding_bonus(flags->width, ft_num_len(*n, base), 0);
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
		return (count + ft_padding_bonus(flags.width, 0, 0));
	count += ft_pre_process(&n, base, &flags, 0);
	count += ft_print_num_base(n, base, lst_base);
	count += ft_post_process(&n, base, &flags);
	return (count);
}
// printf("-----------------------------------\n");
	// printf("Left: %d\n", flags->left);
	// printf("Space: %d\n", flags->space);
	// printf("Zero: %d\n", flags->zero);
	// printf("Width: %d\n", flags->width);
	// printf("precision: %d\n", flags->precision);
	// printf("len: %d\n", ft_num_len(*n, base));
	// printf("-----------------------------------\n");