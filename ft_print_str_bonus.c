/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:26:20 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/24 15:17:21 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_process_str(
	int *str_len,
	t_flag_format *f,
	t_output_format *o)
{
	if (f->precision >= 0 && f->precision < *str_len)
		*str_len = f->precision;
	if (f->width > *str_len)
	{
		if (f->left == 1)
			o->right_spaces = f->width - *str_len;
		else
			o->left_spaces = f->width - *str_len;
	}
	
}

static int	ft_process_print_str(char *str, int str_len, t_flag_format *f)
{
	int				len;
	t_output_format	o;

	len = 0;
	o = ft_output_format_init(f);
	if (str_len == 0 || str == NULL)
	{
		if (f->width == 1)
		{
			str_len = 1;
			if (f->zero == 1)
				str = "0";
			else
				str = " ";
		}
	}
	else
	{
		ft_process_str(&str_len, f, &o);
	}
	len = ft_print_output_str(str, str_len, &o);
	if (len == -1)
		return (-1);
	return (len);
}

#ifdef __APPLE__

int	ft_print_str_bonus(char *str, t_flag_format flags)
{
	int	len;
	int	str_len;

	str_len = 0;
	if (str == NULL)
	{
		if (flags.precision == -1 || flags.precision >= 6)
		{
			str = "(null)";
			str_len = 6;
		}
	}
	else
		str_len = (int)ft_strlen(str);
	
	len = ft_process_print_str(str, str_len, &flags);
	return (len);
}

#else

int	ft_print_str_bonus(char *str, t_flag_format flags)
{
	int	len;
	int	str_len;

	if (str == NULL)
	{
		if (flags.precision == -1 || flags.precision >= 6)
		{
			str = "(null)";
			str_len = 6;
		}
		else
		{
			str = "";
			str_len = 0;
		}
	}
	else
		str_len = (int)ft_strlen(str);
	len = ft_process_print_str(str, str_len, &flags);
	if (len == -1)
		return (-1);
	return (len);
}

#endif