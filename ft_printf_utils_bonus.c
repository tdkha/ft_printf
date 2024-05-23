/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:02:47 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/23 10:36:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_lltoa(long long n)
{
	char		*res;
	size_t		len;
	long		num;

	num = n;
	len = ft_count_digits(n);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	*(res + len) = '\0';
	while (len--)
	{
		*(res + len) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(res + 0) = '-';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
