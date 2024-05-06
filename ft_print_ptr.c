/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:35:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/04/29 14:40:22 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	wrote = write(1, "0x", 2);
	if (wrote == -1)
		return (-1);
	len += wrote;
	if (!ptr)
	{
		wrote = write(1, "0", 1);
		if (wrote == -1)
			return (-1);
		len += wrote;
	}
	else
	{
		wrote = ft_print_address(ptr);
		if (wrote == -1)
			return (-1);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
