/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:26:20 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/21 09:19:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_process_str(
	int num_len,
	t_flag_format *f,
	t_output_format *o
)
{

}

int	ft_process_print_str(
	char *str,
	int num_len,
	t_flag_format *f
	)
{
	int				len;
	t_output_format	o;

	len = 0;
	o = ft_output_format_init(f);

	return (len);
}

int	ft_print_str_bonus(char *str, t_flag_format flags)
{
	int	len;
	int	num_len;

	len = 0;

	return (len);
}