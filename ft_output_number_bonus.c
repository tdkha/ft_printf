/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_number_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:01:11 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/20 15:10:04 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*num_to_str(
	long long n,
	char *str_base,
	char *str,
	int index)
{
	size_t	base;

	base = ft_strlen(str_base);
	if (n < 0 && base == 10)
	{
		n *= -1;
	}
	if (n >= (long long) base)
	{
		str = num_to_str(n / base, str_base, str, index - 1);
	}
	str[index] = str_base[n % base];
	return (str);
}

static int	ft_print_sign_output(
	long long *n,
	char *str,
	int i,
	t_output_format *o)
{
	if (o->left_zeros > 0)
	{
		if (*n < 0)
		{
			str[i++] = '-';
			*n *= -1;
		}
		else if (o->sign == 1 && *n >= 0)
			str[i++] = '+';
		o->sign = 0;
		return (i);
	}
	if (o->left_zeros <= 0 && o->left_spaces <= 0)
	{
		if (o->sign == 1 && *n >= 0)
			str[i++] = '+';
		else if (*n < 0)
		{
			str[i++] = '-';
			*n *= -1;
		}
		o->sign = 0;
	}
	return (i);
}

static void	ft_print_output_num_extent(
				long long n,
				t_output_format *o,
				char	*str,
				char *base)
{
	int		i;
	int		num_len;

	i = 0;
	num_len = ft_num_len_base_output(n, ft_strlen(base), *o);
	i += ft_print_padding_output(str, i, &o->left_spaces, 0);
	i = ft_print_sign_output(&n, str, i, o);
	i = ft_print_prefix_0x_output(n, str, i, o);
	i = ft_print_padding_output(str, i, &o->left_zeros, 1);
	i = ft_print_sign_output(&n, str, i, o);
	if (o->no_value != 1)
	{
		num_to_str(n, base, str, ((i - 1) + num_len));
		i += num_len;
	}
	i = ft_print_padding_output(str, i, &o->right_zeros, 1);
	i = ft_print_padding_output(str, i, &o->right_spaces, 0);
	str[i] = '\0';
	write(1, str, i);
}

int	ft_print_output_num(
	long long n,
	t_output_format *o,
	t_flag_format *f,
	char *base)
{
	int		len;
	char	*str;

	len = o->left_zeros + o->right_zeros + o->left_spaces + o->right_spaces;
	len += (o->sign || n < 0) + ft_num_len_flag(n, *f);
	if (f->precision == 0 && n == 0)
		o->no_value = 1;
	if (o->hash == 1 && n != 0 && ft_strlen(base) == 16)
		len += 2;
	if (len > 0)
	{
		str = (char *) malloc (sizeof(char) * (len + 1));
		if (!str)
			return (0);
		ft_print_output_num_extent(n, o, str, base);
		free(str);
	}
	return (len);
}
// printf("Sign: %d\n", o->sign);
	// printf("Left zero: %d\n", o->left_zeros);
	// printf("Left space:: %d\n", o->left_spaces);
	// printf("Right zero: %d\n", o->right_zeros);
	// printf("Right space:: %d\n", o->right_spaces);