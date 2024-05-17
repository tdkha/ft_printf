/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:45:23 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/17 13:50:22 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_num_len_flag(long long n, t_flag_format f)
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

int	ft_num_len_base(long long n, int base)
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