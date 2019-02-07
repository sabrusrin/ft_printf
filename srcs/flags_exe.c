/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/02/08 01:46:35 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_sup.h"

double	ft_pow(double d, int pow)
{
	return (pow ? (d * ft_pow(d, pow - 1)) : 1);
}

void	do_width(t_mdfrs *m, char f)
{
	char	fl;
	int		c;

	c = 0;
	fl = ' ';
	if (ft_strchr(m->flag, '0'))
		fl = '0';
	if ((f == 'R') && !(ft_strchr(m->flag, '-')) && (m->width))
		while((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	if ((f == 'L') && (fl != '0') && ft_strchr(m->flag, '-') && (m->width))
		while((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	m->c_num += c;
}

void	do_hash(t_mdfrs *m, int f)
{
	if (!f && (m->spec == 'o'))
		m->c_num++;
	else if (!f && (m->spec == 'x' || m->spec == 'X'))
		m->c_num += 2;
	if ((f == 1) && (m->spec == 'x' || m->spec == 'X'))
	{
		ft_putchar('0');
		ft_putchar(m->spec);
	}
	else if ((f == 1) && m->spec == 'o')
		ft_putchar('0');
}

void	pf_putnbr(int n, t_mdfrs *m)
{
	char	sign;
	
	sign = 0;
	m->c_num = count_num(n);
	if (ft_strchr(m->flag, '+') && (n > 0) && (sign = '+'))
		(m->c_num)++;
	else if (ft_strchr(m->flag, '+') && (n > 0) && (sign = ' '))
		(m->c_num)++;
	do_width(m, 'R');
	if (sign)
		write(1, &sign, 1);
	ft_putnbr(n);
	do_width(m, 'L');
}

void	pf_putdbl(double d, t_mdfrs *m)
{
	double	dpart;
	int		ipart;
	int		i;

	ipart = (int)d;
	i = count_num(ipart);
	dpart = d - (double)ipart;
	if (m->preci && (m->preci != -2))
		m->c_num = m->preci + 1 + i;
	else if ((m->preci == -2) && ft_strchr(m->flag, '#'))
		m->c_num = i + 1;
	do_width(m, 'R');
	ft_putnbr(ipart);
	if (m->preci && (m->preci != -2) && write(1, ".", 1))
	{
		(m->preci) == -1 ? (m->preci = 6) : 1;
		P_PRECI;
	}
	((m->preci == -2) && ft_strchr(m->flag, '#')) ? ft_putchar('.') : 1;
	do_width(m, 'L');
}

void	pf_base(unsigned int num, t_mdfrs *m)
{
	char	*int_list;
	char	buffer[50];
	char	*ptr;
	int		base;

	if (m->spec == 'X' || m->spec == 'x')
		base = 16;
	else if (m->spec == 'o')
		base = 8;
	(m->spec == 'X') ? (int_list = "0123456789ABCDEF") :
		(int_list = "0123456789abcdef");
	ptr = &buffer[49];
	*ptr = '\0';
	if (!num && ++m->c_num)
		ptr = "0";
	while (num != 0 && ++m->c_num && (*--ptr = int_list[num % base]))
		num /= base;
	ft_strchr(m->flag, '#') ? do_hash(m, 0) : 1;
	do_width(m, 'R');
	ft_strchr(m->flag, '#') ? do_hash(m, 1) : 1;
	ft_putstr(ptr);
	do_width(m, 'L');
}
