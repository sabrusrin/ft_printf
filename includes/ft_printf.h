/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 23:19:51 by chermist          #+#    #+#             */
/*   Updated: 2019/02/04 23:16:15 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_sup.h"

typedef struct	s_mdfrs
{
	char	flag[6];
	char	*modifier;
	int		width;
	int		precision;
}				t_mdfrs;

# define PF_CHAR(x) {ft_putchar(x); return(1);}
# define PF_NBR(x) {i = x; ft_putnbr(i); return(count_num(i));}
# define PF_STR(x) {return(ft_putstr(x));}
# define SPCFR(x) (ft_strchr("diouxXfeEcspaAgG", x) != NULL)
# define FLAGS(x) (ft_strchr("-+ '#0", x) != NULL)
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)

#endif
