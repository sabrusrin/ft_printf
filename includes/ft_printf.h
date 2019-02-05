/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:16:57 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/05 23:52:09 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_sup.h"



# define PF_CHAR(x) {ft_putchar(x); return(1);}
# define PF_NBR(x) {i = x; mods->c_num = count_num(i); \
					pf_putnbr(i, mods); return (mods->c_num);}
# define PF_STR(x) {return (ft_putstr(x));}
# define PF_DBL(x) {return (pf_putdouble((double)x));}
# define SPCFR(x) (ft_strchr("diouxXfeEcspaAgG", x) != NULL)
# define FLAGS(x) (ft_strchr("-+ #0", x) != NULL)
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)

#endif
