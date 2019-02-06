/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:13:19 by chermist          #+#    #+#             */
/*   Updated: 2019/02/07 01:22:20 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUP_H
# define FT_SUP_H
# include "ft_printf.h"

typedef struct	s_mdfrs
{
	char	flag[6];
	char	*modifier;
	int		width;
	int		preci;
	char	spec;
	int		c_num;
}				t_mdfrs;

char	*ft_strchr(const char *s, int c);
void	pf_putnbr(int n, t_mdfrs *mods);
void	pf_putdouble(double d, t_mdfrs *mods);
void    ft_putnbr(int n);
int     ft_isdigit(int c);
int     ft_putstr(char const *s);
void    ft_putchar(char c);

# define R_JUST {if (!(ft_strchr(mods->flag, '-')) && (mods->width))\
				while((mods->width)-- > mods->c_num && ++c) write(1, &fl, 1);}
# define L_JUST {if ((fl != '0') && ft_strchr(mods->flag, '-') && (mods->width))\
				while((mods->width)-- > mods->c_num && ++c) write(1, &fl, 1);}
# define F_ZERO {fl = ' '; if (ft_strchr(mods->flag, '0')) fl = '0';}
# define P_PRECI {dpart = dpart * ft_pow(10, mods->preci + 1); \
		dpart = (((int)dpart % 10) > 4) ? dpart / 10 + 1 : dpart / 10; \
		ft_putnbr((int)dpart);}

#endif
