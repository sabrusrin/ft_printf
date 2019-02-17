/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/02/17 16:28:40 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/ft_printf.h"

double	ft_pow(double d, int pow)
{
	return (pow ? (d * ft_pow(d, pow - 1)) : 1);
}

void	do_width(t_mdfrs *m, char f)
{
	char	fl;
	int		c;
	int		ch;

	c = 0;
	fl = ' ';
	ch = ft_strchr(m->flag, '-') ? 1 : 0;
	if (ft_strchr(m->flag, '0') && !ch)
		fl = '0';
	if ((f == 'R') && !ch && (m->width))
		while ((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	if ((f == 'L') && ch && (m->width))
		while ((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	m->c_num += c;
}

void	do_hash(t_mdfrs *m, int f)
{
	if (!f && (m->spec == 'o'))
		m->c_num++;
	else if (!f && (m->spec == 'x' || m->spec == 'X' || m->spec == 'p'))
		m->c_num += 2;
	if ((f == 1) && (m->spec == 'x' || m->spec == 'X' ||
				((m->spec == 'p') ? (m->spec = 'x') : 0)))
	{
		ft_putchar('0');
		ft_putchar(m->spec);
	}
	else if ((f == 1) && m->spec == 'o')
		ft_putchar('0');
}

void	do_preci(t_mdfrs *m, long double dpart, char c)
{
	int	i;

	i = 0;
	if (c == 'f')
	{
		dpart = dpart * ft_pow(10, m->pr + 1);
		dpart = (((long)dpart % 10) > 4) ? dpart / 10 + 1 : dpart / 10;
		ft_putnbr((long)dpart);
	}
	else if (c == 'o')
	{
		i = m->pr;
		while (i--)
			ft_putchar('0');
	}
}
