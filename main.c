/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:13:40 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/13 23:29:23 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	///printf("[%3.1s]\n", "Hello");
	char *ptr = NULL;
	printf("--------------------------\n");
	printf("Comparing\n");
	printf("--------------------------\n");
	ft_printf("[%7i]\n", -14);
	printf("--------------------------\n");
	printf("[%7i]\n", -14);
	printf("--------------------------\n");
	//printf("[%.0s]\n", ptr);
}
