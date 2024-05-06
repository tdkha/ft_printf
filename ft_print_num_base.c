/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:23:41 by ktieu             #+#    #+#             */
/*   Updated: 2024/04/29 16:47:37 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num_base(long long n, int base, char *lst_base)
{
	int		count;
	int		wrote;

	count = 0;
	if (n < 0)
	{
		wrote = ft_check_write_return_count((int) '-');
		if (wrote == -1)
			return (-1);
		return ((ft_print_num_base(-n, base, lst_base)) + 1);
	}
	if (n >= base)
	{
		wrote = ft_print_num_base(n / base, base, lst_base);
		if (wrote == -1)
			return (-1);
		count += wrote;
		wrote = ft_print_num_base(n % base, base, lst_base);
		if (wrote == -1)
			return (-1);
		count += wrote;
		return (count);
	}
	else
		return (ft_check_write_return_count(lst_base[n]));
}
