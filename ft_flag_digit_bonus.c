/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_digit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:52:49 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/03 16:08:42 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag_format	ft_flag_digit_bonus(char c, t_flag_format flags)
{
	if (flags.width_star == 1)
	{
		flags.width = 0;
		return (flags);
	}
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
