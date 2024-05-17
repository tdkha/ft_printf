/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintformat_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:31:16 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/17 11:11:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isspecifier_bonus(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_isflag_bonus(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_isprintformat_bonus(int c)
{
	return (ft_isspecifier_bonus(c) || ft_isflag_bonus(c) || ft_isdigit(c));
}
