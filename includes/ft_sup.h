/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:13:19 by chermist          #+#    #+#             */
/*   Updated: 2019/02/08 03:01:07 by chermist         ###   ########.fr       */
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
void	pf_putnbr(int n, t_mdfrs *m);
void	pf_putdbl(double d, t_mdfrs *m);
void	pf_base(unsigned int num, t_mdfrs *m);
void	ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_putstr(char const *s);
void	ft_putchar(char c);

# define P_PRECI {dpart = dpart * ft_pow(10, m->preci + 1); \
		m->c_num += m->preci; \
		dpart = (((int)dpart % 10) > 4) ? dpart / 10 + 1 : dpart / 10; \
		ft_putnbr((int)dpart);}

#endif
