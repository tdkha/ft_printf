/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:28:24 by ktieu             #+#    #+#             */
/*   Updated: 2024/04/29 14:26:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;
	int	wrote;

	wrote = 0;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		wrote = ft_check_write_return_count((int)*str);
		if (wrote < 0)
			return (-1);
		count++;
		str++;
	}
	return (count);
}
