/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:57:31 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/24 11:19:29 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*-------------------------------------------------------------------------*/
/*	STRUCT	*/
/*-------------------------------------------------------------------------*/

t_output_format	ft_output_format_init(t_flag_format *f)
{
	t_output_format	output;

	output.sign = f->sign;
	output.left = f->left;
	output.hash = f->hash;
	output.left_zeros = 0;
	output.right_zeros = 0;
	output.left_spaces = 0;
	output.right_spaces = 0;
	output.specifier = f->specifier;
	output.no_value = 0;
	return (output);
}

int	ft_print_padding_output(
	char *str,
	int i,
	int *padding,
	int is_zero)
{
	if (is_zero)
	{
		while (*padding > 0)
		{
			str[i++] = '0';
			*padding -= 1;
		}
	}
	else
	{
		while (*padding > 0)
		{
			str[i++] = ' ';
			*padding -= 1;
		}
	}
	return (i);
}

int	ft_print_prefix_0x_output(
	long long n,
	char *str,
	int i,
	t_output_format *o)
{
	if (o->specifier == 'p')
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	else if (o->specifier == 'x' || o->specifier == 'X')
	{
		if (o->hash == 1 && n != 0)
		{
			str[i++] = '0';
			if (o->specifier == 'x')
				str[i++] = 'x';
			else if (o->specifier == 'X')
				str[i++] = 'X';
		}
	}
	return (i);
}
