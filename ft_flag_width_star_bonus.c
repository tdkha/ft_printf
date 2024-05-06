/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width_star_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:52:29 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/03 16:23:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag_format	ft_flag_width_star_bonus(va_list args, t_flag_format flags)
{
	flags.width_star = 1;
	flags.width = va_arg(args, int);
	return (flags);
}
