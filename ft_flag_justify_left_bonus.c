/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_justify_left_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:51:58 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/03 16:09:30 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag_format	ft_flag_justify_left_bonus(t_flag_format flags)
{
	flags.left = 1;
	flags.zero = 0;
	return (flags);
}
