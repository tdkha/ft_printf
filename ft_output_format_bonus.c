/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:57:31 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/17 14:48:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*-------------------------------------------------------------------------*/
/*	STRUCT	*/
/*-------------------------------------------------------------------------*/

t_output_format	output_format_init(t_flag_format *f)
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

/*-------------------------------------------------------------------------*/
/*	NUMBER	*/
/*-------------------------------------------------------------------------*/
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
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= (long long) base)
	{
		str = num_to_str(n / base, str_base, str, index - 1);
	}
	str[index] = str_base[n % base];
	return (str);
}

static void	ft_print_output_num_extent(
				long long n,
				t_output_format *o,
				char	*str,
				char *base)
{
	int		i;
	size_t	base_len;
	int		num_len;
	
	i = 0;
	base_len = ft_strlen(base);
	num_len = ft_num_len_base(n, base_len);
	while (o->left_spaces-- > 0)
		str[i++] = ' ';
	if (o->left_zeros == 1 && o->sign == 1 && n < 0)
		str[i++] = '-';
	else if (o->left_zeros == 1 && o->sign == 1 && n >= 0)
		str[i++] = '+';
	while (o->left_zeros-- > 0)
		str[i++] = '0';
	num_to_str(n, base, str, i + num_len - 1);
	i += num_len;
	while (o->right_zeros-- > 0)
		str[i++] = '0';
	while (o->right_spaces-- > 0)
		str[i++] = ' ';
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
	len += (o->sign + ft_num_len_flag(n, *f));
	if (n < 0 && o->sign == 0)
		len++;
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_print_output_num_extent(n, o, str, base);
	free(str);
	return (len);
}
