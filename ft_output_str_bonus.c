/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:16:39 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/21 15:18:04 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_str_to_str(char *str, char *res, int str_len, int index)
{
	int	i;

	i = 0;
	if (str_len == 0)
		return (index);
	while (i < str_len)
	{
		res[index] = str[i];
		index++;
		i++;
	}
	return (index);
}

int	ft_print_output_str(char *str, int str_len, t_output_format *o)
{
	char	*res;
	int		malloc_len;
	int		i;

	i = 0;
	malloc_len = o->left_spaces + o->right_spaces + str_len;
	res = (char *) malloc(sizeof(char) * (malloc_len + 1));
	if (!res)
        return 0;
	i = ft_print_padding_output(res, i, &o->left_spaces, 0);
	i = ft_str_to_str(str, res, str_len, i);
	i = ft_print_padding_output(res, i, &o->right_spaces, 0);
	res[i] = '\0';
	write(1, res, malloc_len);
	free(res);
	return (malloc_len);
}
