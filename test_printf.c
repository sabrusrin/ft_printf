/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:42:17 by chermist          #+#    #+#             */
/*   Updated: 2019/02/04 19:10:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

int		ft_printf(const char *format, ...);

int		main(void)
{
	char *st = "Umnozheniye串€";

	ft_putnbr(printf("F%#8.2f   %8d  %s %#X %#o \n", 3.1435333345, 5675,  "Привет мир😊 ", 123, 123));

	ft_putstr("\nOUR printf:");

	ft_putnbr(ft_printf("\nПривет%c \\%s %d * %d = %d\\"
			"☺️ Как дела%c%c", 46, st, 5, 6, 5*6, 63, 10));
	
	ft_putstr("\nLIBC printf:");
	
	ft_putnbr(printf("\nПривет%c \\%s %d * %d = %d\\"
			"☺️ Как дела%c%c", 46, st, 5, 6, 5*6, 63, 10));
	ft_printf("\nпривет");
}
