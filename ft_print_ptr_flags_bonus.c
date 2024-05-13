/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:04:46 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/12 17:26:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static int	ft_print_address(unsigned long num)
{
	int		wrote;

	wrote = 1;
	if (num >= 16)
	{
		ft_print_address(num / 16);
		ft_print_address(num % 16);
	}
	else
	{
		if (num < 10)
			wrote = ft_print_char(num + '0');
		else
			wrote = ft_print_char('a' + (num - 10));
		if (wrote < 0)
			return (-1);
	}
	return (wrote);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;
	int	wrote;

	len = 0;
	if (ptr == 0)
	{
		wrote = ft_print_str(PTR_NULL);
		if (wrote == -1)
			return (-1);
		len += wrote;
		return (len);
	}
	wrote = write(1, "0x", 2);
	if (wrote == -1)
		return (-1);
	len += wrote;
	wrote = ft_print_address(ptr);
	if (wrote == -1)
		return (-1);
	len += ft_ptr_len(ptr);
	return (len);
}

int	ft_print_ptr_flags_bonus(unsigned long ptr, t_flag_format flags)
{
	int	len;

	len = 0;
	if (!ptr)
		flags.width -= ft_strlen(PTR_NULL);
	else
		flags.width -= 2;
	if (flags.left == 1)
		len += ft_print_ptr(ptr);
	len += ft_padding_bonus(flags.width, ft_ptr_len(ptr), 0);
	if (flags.left == 0)
		len += ft_print_ptr(ptr);
	return (len);
}
