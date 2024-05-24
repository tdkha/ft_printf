/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:52:54 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/24 14:59:42 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	c = 'a';
	int		count1;
	int		count2;
	// printf("-----------------------------------\n");
	// printf("Testing padding zero with character\n");
	// printf("-----------------------------------\n");
	// count1 = printf("%05c\n", c);
	// printf("\n");
	// count2 = ft_printf("%05c\n", c);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");
	// printf("Testing padding spaces with character\n");
	// printf("-----------------------------------\n");
	// count1 = printf("%5c\n", c);
	// printf("\n");
	// count2 = ft_printf("%5c\n", c);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");
	// count1 = printf("%" "5c\n", c);
	// printf("\n");
	// count2 = ft_printf("%" "5c\n", c);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);

	// printf("-----------------------------------\n");
	// printf("Testing Unsigned number\n");
	// printf("-----------------------------------\n");

	// count1 = printf("%#0 u\n", 10);
	// count2 = ft_printf("%#0 u\n", 10);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0- +u\n", 0);
	// count2 = ft_printf("%#0- +u\n", 0);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0+- u\n", 0);
	// count2 = ft_printf("%#0+- u\n", 0);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0- u\n", 0);
	// count2 = ft_printf("%#0- u\n", 0);
	// printf("Difference: %d\n", count1 - count2);

	printf("-----------------------------------\n");
	printf("Testing number\n");
	printf("-----------------------------------\n");
	// count1 = printf("%d", INT_MIN);
	// printf("\n");
	// count2 = ft_printf("%d", INT_MIN);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0- d\n", 10);
	// count2 = ft_printf("%#0- d\n", 10);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0- d\n", 1);
	// count2 = ft_printf("%#0- d\n", 1);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0- d\n", -8);
	// count2 = ft_printf("%#0- d\n", -8);
	// printf("Difference: %d\n", count1 - count2);

	// count1 =  printf("%#0- +d\n", 0);
	// count2 =  ft_printf("%#0- +d\n", 0);
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#0 d\n", 0);
	// count2 = ft_printf("%#0 d\n", 0);
	// printf("Difference: %d\n", count1 - count2);

	// printf("-----------------------------------\n");
	// printf("Testing pointer\n");
	// printf("-----------------------------------\n");
	
	// printf("Hash case:\n");
	// count1 = printf("%#p", 42);
	// printf("\n");
	// count2 = ft_printf("%#p", 42);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");
	
	// printf("NULL case:\n");
	// count1 = printf("%0.p\n", (void*)0);
	// count2 = ft_printf("%0.p\n", (void*)0);
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");
	// count1 = printf("%0.1p\n", (void*)0);
	// count2 = ft_printf("%0.1p\n", (void*)0);
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");
	// count1 = printf("%0.2p\n", (void*)0);
	// count2 = ft_printf("%0.2p\n", (void*)0);
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");

	// printf("Precision case:\n");
	// count1 = printf("%.12p", main);
	// printf("\n");
	// count2 = ft_printf("%.12p", main);
	// printf("\n");
	// printf("Difference: %d\n", count1 - count2);
	// printf("-----------------------------------\n");

	// count1 = printf("%#0- 1i\n", 0);
	// count2 = ft_printf("%#0- 1i\n", 0);
	// printf("Difference: %d\n", count1 - count2);


	// printf("-----------------------------------\n");
	// printf("Testing string\n");
	// printf("-----------------------------------\n");
	// printf("Special case where string should print 0\n");
	// count1 = printf("%#01s\n", "");
	// count2 = ft_printf("%#01s\n", "");
	// printf("Difference: %d\n", count1 - count2);

	// count1 = printf("%#01s\n", "\0");
	// count2 = ft_printf("%#01s\n", "\0");
	// printf("Difference: %d\n", count1 - count2);

	count1 = printf("%#01.s\n", "");
	count2 = ft_printf("%#01.s\n", "");
	printf("Difference: %d\n", count1 - count2);

	
}