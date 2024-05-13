/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:56:15 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/12 14:42:26 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_padding_bonus(int max_width, int len, int has_zero_pad)
{
	int	count;
	int	iteration;
	int	wrote;

	wrote = 0;
	count = 0;
	iteration = max_width - len;
	while (iteration > 0)
	{
		if (has_zero_pad)
			wrote = ft_print_char('0');
		else
			wrote = ft_print_char(' ');
		if (wrote < 0)
			return (-1);
		count += wrote;
		iteration--;
	}
	return (count);
}
