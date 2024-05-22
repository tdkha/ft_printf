/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:07:37 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/22 13:35:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

#ifdef __APPLE__

static int	ft_print_nullptr(char *str, int index)
{
	char	*ptr_null;
	size_t	len;
	int		i;

	ptr_null = "0x0";
	i = 0;
	len = ft_strlen(ptr_null);
	while (len > 0)
	{
		str[index] = ptr_null[i];
		i++;
		index++;
		len--;
	}
	return (index);
}

#else

static int	ft_print_nullptr(char *str, int index)
{
	char	*ptr_null;
	size_t	len;
	int		i;

	ptr_null = "(nil)";
	i = 0;
	len = ft_strlen(ptr_null);
	while (len > 0)
	{
		str[index] = ptr_null[i];
		i++;
		index++;
		len--;
	}
	return (index);
}
#endif

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

int	ft_print_output_ptr(unsigned long ptr, int num_len, t_output_format *o)
{
	int		i;
	int		str_len;
	char	*str;

	str_len = o->left_spaces + o->right_spaces + num_len;
	str = (char *) malloc (sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (-1);
	i = 0;
	i = ft_print_padding_output(str, i, &o->left_spaces, 0);
	if (!ptr)
		i = ft_print_nullptr(str, i);
	else
	{
		i = ft_print_prefix_0x_output(ptr, str, i, o);
		ft_address_to_str(ptr, str, (i - 1) + (num_len - ft_strlen("0x")));
		i += num_len - ft_strlen("0x");
	}
	i = ft_print_padding_output(str, i, &o->right_spaces, 0);
	str[i] = '\0';
	if (write(1, str, str_len) != str_len)
		return (free(str), -1);
	free(str);
	return (str_len);
}
