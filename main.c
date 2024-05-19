/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:13:40 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/19 18:31:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	///printf("[%3.1s]\n", "Hello");
	char *ptr = NULL;
	int count1 = ft_printf("%013.i",-1488496170);
	printf("\n");
	printf("Count 1: %d\n", count1);
	printf("--------------------------\n");
	int count2 = printf("%013.i" ,-1488496170);;
	printf("\n");
	printf("Count 2: %d\n", count2);
	printf("--------------------------\n");
	//printf("[%.0s]\n", ptr);
}
