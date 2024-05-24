/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:55:51 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/20 16:32:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_output_print_char(int c, t_output_format *o)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = o->left_spaces + o->left_zeros + 1 + o->right_spaces + o->right_zeros;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	i = ft_print_padding_output(str, i, &o->left_spaces, 0);
	i = ft_print_padding_output(str, i, &o->left_zeros, 1);
	str[i++] = (char)c;
	i = ft_print_padding_output(str, i, &o->right_spaces, 0);
	i = ft_print_padding_output(str, i, &o->right_zeros, 1);
	str[i] = '\0';
	if (write(1, str, i) != i)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

static void	ft_process_char(t_flag_format *f, t_output_format *o)
{
	if (f->width > 1)
	{
		if (f->zero == 1)
		{
			if (f->left == 1)
				o->right_zeros = f->width - 1;
			else
				o->left_zeros = f->width - 1;
		}
		else
		{
			if (f->left == 1)
				o->right_spaces = f->width - 1;
			else
				o->left_spaces = f->width - 1;
		}
	}
}

static int	ft_process_print_char(int c, t_flag_format *f)
{
	int				len;
	t_output_format	o;

	o = ft_output_format_init(f);
	ft_process_char(f, &o);
	len = ft_output_print_char(c, &o);
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_print_char_bonus(int c, t_flag_format flags)
{
	int	len;

	len = ft_process_print_char(c, &flags);
	if (len == -1)
		return (-1);
	return (len);
}
