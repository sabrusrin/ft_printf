/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:16:57 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/08 01:26:31 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_sup.h"


int		count_num(int i);

# define PF_CHAR(x) {ft_putchar(x); return(1);}
//# define PF_STR(x) {return (ft_putstr(x));}
//# define PF_DBL(x) {pf_putdouble((double)x, mods); return (mods->c_num);}
//# define PF_BASE(x) {pf_base(x, mods); return (mods->c_num);}
# define SPCFR(x) (ft_strchr("diouxXfeEcspaAgG", x) != NULL)
# define FLAGS(x) (ft_strchr("-+ #0", x) != NULL)
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)

#endif
