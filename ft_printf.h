/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:19:51 by chermist          #+#    #+#             */
/*   Updated: 2019/02/04 00:00:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_mdfrs
{
	char	flag[6];
	char	*modifier;
	int		width;
	int		precision;
}				t_mdfrs;

# define PF_CHAR(x) {ft_putchar(x); return(1);}
# define PF_NBR(x) {ft_putnbr(x); return(count_num(i));}
# define PF_STR(x) {return(ft_putstr(x));}
# define SPCFR(x) ((x == 'd') || (x == 'i') || (x == 'o') || \
					(x == 'u') || (x == 'x') || (x == 'X') || \
					(x == 'f') || (x == 'e') || (x == 'E') || \
					(x == 'c') || (x == 's') || (x == 'p') || \
					(x == 'a') || (x == 'A') || (x == 'g') || (x == 'G'))
# define FLAGS(x) ((x == '-') || (x == '+') || (x == ' ') || (x == '#') || (x == '0'))
# define MDFR(x) ((x == 'l') || (x == 'L') || (x == 'h') || (x == 'j') || (x == 'z'))

#endif
