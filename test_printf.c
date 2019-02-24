/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:42:17 by chermist          #+#    #+#             */
/*   Updated: 2019/02/25 02:37:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/ft_sup.h"
#include <limits.h>
#include <locale.h>

int		ft_printf(const char *format, ...);

int		main(void)
{
	//wchar_t hp = u&0x1F600
	char *st = "Umnozheniye串€";
	float t = 3.14;
	unsigned long l;

	setlocale(LC_ALL, "ru_RU.UTF-8");
	 //short int		s = 23458;

	//ft_putnbr(printf("F%#8.2f   %8d  %s %#X %#o \n", 3.1435333345, 5675,  "Привет мир😊 ", 123, 123));

	/* ft_putstr("\nOUR printf:");
 	ft_putstr("\nOUR printf:");

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
	printf("\n%s is a string", NULL);

	//ft_printf("\n%p", &st);
	ft_printf("\n|%x|", -42);
	ft_printf("\n|%8p|", &t);
	printf("\n|%8p|", &t);
	ft_printf("\n"); 
//	ft_putnbr(ft_printf("\n% 05u is a string\n%n%+05d\n", 8, count, 16));
//	ft_printf("\npointer: %d\n", *count);
//	ft_putnbr(printf("\n%05u is a string\n%n%+05d\n", 8, count, 16));
//	printf("\npointer: %d\n", *count);

	ft_putnbr(ft_printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415));
	ft_putnbr(printf("\nnum: %.f, |%  #.f, %+f, %.2f, %#.0f\n", 3.1415, 3.1415, -3.1415, 3.1415, 3.1415));

	printf("\n%x", -42);
	ft_printf("\n%x\n", -42);

	ft_printf("\n|%5.o|", 0);
	printf("\n|%5.o|", 0);

	ft_putnbr(printf("\n|%.5p|\n", 0));
	ft_putnbr(ft_printf("\n|%.5p|\n", 0));
	ft_putnbr(ft_printf("\n|%d|\n", 1));
	ft_putnbr(printf("\n|%d|\n", 1));
	ft_printf("\n|%5.o|", 0);
	printf("\n|%5.o|", 0);
	ft_printf("\n|%-5%|", 0);
	ft_printf("\n%05.0d", -42);
	ft_printf("\n%+5.2d", -42);
	printf("\n%05.0d", -42);
	printf("\n%+5.2d", -42);
	printf("\n%05d", -42);
	ft_printf("\n%05d", -42);
	ft_printf("\n%+10.5d", 4242);
	printf("\n%+10.5d", 4242);
	ft_printf("\n%+10.5d", -4242);
	printf("\n%+10.5d", -4242);
	ft_printf("\n|%10.5d|", -4242);
	printf("\n|%10.5d|", -4242);
	ft_printf("\n|@f: %5.d| %5.0d|", 0, 0);
	printf("\n|@p: %5.d| %5.0d|", 0, 0); */
//	ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
//	printf("\n@main_ftprintf: %####0000 33..1..#00d\n", 256);

	ft_putnbr(ft_printf("\n{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	ft_putnbr(printf("\n{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	ft_putnbr(ft_printf("\n%#.O\n", 0));
	ft_putnbr(printf("\n%#.O\n", 0));
	ft_putnbr(ft_printf("\n%#.x, %#.0x\n", 0, 0));
	ft_putnbr(printf("\n%#.x, %#.0x\n", 0, 0));
	ft_putnbr(ft_printf("\n{%05.S}\n", L"42 c est cool"));
	ft_putnbr(printf("\n{%05.S}\n", L"42 c est cool"));
	ft_putnbr(ft_printf("\n{%05.s}\n", 0));
	ft_putnbr(printf("\n{%05.s}\n", 0));
	ft_putnbr(ft_printf("\n{%05.Z}\n", 0));
	ft_putnbr(ft_printf("\n{%05.Z}\n", 0));
	ft_putnbr(ft_printf("\n{%#.5x}\n", 1));
	ft_putnbr(printf("\n{%#.5x}\n", 1));

}
