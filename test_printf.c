/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:42:17 by chermist          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/02/17 13:43:07 by chermist         ###   ########.fr       */
=======
/*   Updated: 2019/02/17 16:28:32 by chermist         ###   ########.fr       */
>>>>>>> 42a682abfd207b7a19b162d5570519a1517b3c33
/*                                                                            */
/* ************************************************************************** */


<<<<<<< HEAD
=======

>>>>>>> 42a682abfd207b7a19b162d5570519a1517b3c33
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/ft_sup.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	char *st = "Umnozheniye串€";
	float t = 3.14;
	 //short int		s = 23458;

	//ft_putnbr(printf("F%#8.2f   %8d  %s %#X %#o \n", 3.1435333345, 5675,  "Привет мир😊 ", 123, 123));

	/*ft_putstr("\nOUR printf:");

	ft_putnbr(ft_printf("\nПривет%c \\%s %d * %d = %d\\"
			"💃 Как дела%c%8d|%#+0+5.f|%c", 46, st, 5, 6, 5*6, 63, 228, 3.1415, 10));
	
	ft_putstr("\nLIBC printf:");
	
	ft_putnbr(printf("\nПривет%c \\%s %d * %d = %d\\"
			"💃 Как дела%c%8d|%#0+5.f|%c", 46, st, 5, 6, 5*6, 63, 228, 3.1415, 10));
	ft_printf("\nпривет");
	ft_putnbr(ft_printf("\n%f, %.f, %#.f, %.2f, %#.0f\n", -3.1415, 3.1415, 3.1415, 3.1415, 3.1415));
	ft_putnbr(printf("\n%f, %.f, %#.f, %.2f, %#.0f\n", -3.1415, 3.1415, 3.1415, 3.1415, 3.1415));
	ft_putnbr(ft_printf("\n%05x, %x, %4o, %#5o\n", -123, 42, 123, 123));
	ft_putnbr(printf("\n%05x, %#x, %4o, %#5o\n", -123, 123, 123, 123));
	ft_putnbr(ft_printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415));
	ft_putnbr(printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415));
	ft_printf("\n!!!!num: %x, %o", 123, 123);

	ft_putnbr(ft_printf("\n%c, |%05c|, |%-05c|\n", 65, 65, 65));
	ft_putnbr(printf("\n%c, |%05c|, |%-05c|\n", 65, 65, 65));


	ft_printf("\n");
	ft_printf("\n%s is a string", NULL);
//	printf("\n%s is a string", NULL);

	//ft_printf("\n%p", &st);
	ft_printf("\n|%x|", -42);
	ft_printf("\n|%8p|", &t);
	printf("\n|%8p|", &t);
	ft_printf("\n"); */
/* 	ft_putnbr(ft_printf("\n% 05u is a string\n%n%+05d\n", 8, count, 16));
	ft_printf("\npointer: %d\n", *count);
	ft_putnbr(printf("\n%05u is a string\n%n%+05d\n", 8, count, 16));
	printf("\npointer: %d\n", *count);

	ft_putnbr(ft_printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415));
	ft_putnbr(printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415)); */

	//printf("\n%x", -42);
	//ft_printf("\n%x\n", -42);
<<<<<<< HEAD
	ft_printf("\n|%5.o|", 0);
	printf("\n|%5.o|", 0);
<<<<<<< HEAD

	ft_putnbr(printf("\n|%.5p|\n", 0));
	ft_putnbr(ft_printf("\n|%.5p|\n", 0));
=======
	ft_putnbr(ft_printf("\n|%d|\n", 1));
	ft_putnbr(printf("\n|%d|\n", 1));
=======
	//ft_printf("\n|%5.o|", 0);
//	printf("\n|%5.o|", 0);
ft_printf("%-5%", 0);
>>>>>>> 36d618c9c21d323f0d13aabd4baac8cdd9fc1c9c
>>>>>>> 42a682abfd207b7a19b162d5570519a1517b3c33
}
