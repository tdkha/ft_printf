/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:07:37 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/20 15:22:32 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_address_to_str(
	unsigned long n,
	char *str,
	int index)
{
	size_t	base;
	char	*str_base;

	str_base = "0123456789abcdef";
	base = 16;
	if (n >= base)
		str = ft_address_to_str(n / base, str, index - 1);
	str[index] = str_base[n % base];
	return (str);
}

int	ft_print_output_ptr(unsigned long ptr, size_t num_len, t_output_format *o)
{
	int		i;
	int		str_len;
	char	*str;

	str_len = ft_strlen("0x") + o->left_spaces + o->right_spaces + num_len;
	str = (char *) malloc (sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	i = ft_print_padding_output(str, i, &o->left_spaces, 0);
	i = ft_print_prefix_0x_output(ptr, str, i, o);
	ft_address_to_str(ptr, str, (i - 1) + num_len);
	i += num_len;
	i = ft_print_padding_output(str, i, &o->right_spaces, 0);
	str[i] = '\0';
	write(1, str, str_len);
	free(str);
	return (str_len);
}
