/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:42:17 by chermist          #+#    #+#             */
/*   Updated: 2019/02/07 02:20:08 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/ft_sup.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	char *st = "Umnozheniye串€";
	//float t = 3.14;
	 //short int		s = 23458;

	ft_putnbr(printf("F%#8.2f   %8d  %s %#X %#o \n", 3.1435333345, 5675,  "Привет мир😊 ", 123, 123));

	ft_putstr("\nOUR printf:");

	ft_putnbr(ft_printf("\nПривет%c \\%s %d * %d = %d\\"
			"💃 Как дела%c%8d|%0#5.f|%c", 46, st, 5, 6, 5*6, 63, 228, 3.1415, 10));
	
	ft_putstr("\nLIBC printf:");
	
	ft_putnbr(printf("\nПривет%c \\%s %d * %d = %d\\"
			"💃 Как дела%c%8d|%0#5.f|%c", 46, st, 5, 6, 5*6, 63, 228, 3.1415, 10));
	ft_printf("\nпривет");
	ft_printf("\n%f, %.f, %#.f, %.2f, %.0f", 3.1415, 3.1415, 3.1415, 3.1415, 3.1415);
	printf("\n%f, %.f, %#.f, %.2f, %.0f\n", 3.1415, 3.1415, 3.1415, 3.1415, 3.1415);
}
