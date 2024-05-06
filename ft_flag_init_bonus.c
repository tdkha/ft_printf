/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:51:44 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/03 16:08:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag_format	ft_flag_init_bonus(void)
{
	t_flag_format	format;

	format.sign = 0;
	format.left = 0;
	format.zero = 0;
	format.hash = 0;
	format.space = 0;
	format.width = 0;
	format.width_star = 0;
	format.precision = -1;
	format.precision_width = 0;
	format.specifier = 0;
	return (format);
}
