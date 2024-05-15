/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_flags_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:55:51 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/14 11:40:12 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char_flags_bonus(int c, t_flag_format flags)
{
	int	count;
	int	wrote;

	wrote = 0;
	count = 0;
	if (flags.left == 1)
	{
		wrote = ft_print_char(c);
		if (wrote < 0)
			return (-1);
		count += wrote;
	}
	wrote = ft_pad_bonus(flags.width, 1, flags.zero);
	if (wrote < 0)
		return (-1);
	count += wrote;
	if (flags.left == 0)
	{
		wrote = ft_print_char(c);
		if (wrote < 0)
			return (-1);
		count += wrote;
	}
	return (count);
}
