/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:13:40 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/20 15:18:19 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	main(void)
{
	///printf("[%3.1s]\n", "Hello");
	long value = LONG_MIN;
	char *ptr = NULL;
	int count1 = ft_printf("%-1p %-2p", 0, 0);
	printf("\n");
	printf("Count 1: %d\n", count1);
	printf("--------------------------\n");
	int count2 = printf("%-1p %-2p", 0, 0);
	printf("\n");
	printf("Count 2: %d\n", count2);
	printf("--------------------------\n");
	//printf("[%.0s]\n", ptr);
}
