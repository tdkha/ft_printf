/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_write_return_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:57:37 by ktieu             #+#    #+#             */
/*   Updated: 2024/04/29 13:02:50 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_write_return_count(int c)
{
	int	wrote;

	wrote = ft_print_char(c);
	if (wrote < 0)
		return (-1);
	else
		return (1);
}
