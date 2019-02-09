/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/02/09 22:19:51 by chermist         ###   ########.fr       */
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
		while ((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	if ((f == 'L') && (fl != '0') && ft_strchr(m->flag, '-') && (m->width))
		while ((m->width)-- > m->c_num && ++c)
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
	int		f;

	f = ft_strchr(m->flag, '+') ? 1 : 0;
	sign = 0;
	m->c_num = count_num(n);
	if (ft_strchr(m->flag, '+') && (n > 0) && (sign = '+'))
		(m->c_num)++;
	else if (ft_strchr(m->flag, ' ') && (n > 0) && (sign = ' '))
		(m->c_num)++;
	do_width(m, 'R');
	(sign) ? write(1, &sign, 1) : 1;
	ft_putnbr(n);
	do_width(m, 'L');
}

void	pf_putdbl(double d, t_mdfrs *m)
{
	double	dpart;
	long	ip;
	char	sign;
	int		pr;

	sign = 0;
	pr = m->preci;
	ip = (long)(d < 0) ? -d : d;
	m->c_num = count_num(ip) + ((d < 0) ? 1 : 0);
	dpart = ((d < 0) ? -d : d) - ip;
	if (ft_strchr(m->flag, '+') && (d > 0) && (sign = '+'))
		(m->c_num)++;
	else if (ft_strchr(m->flag, ' ') && (d > 0) && (sign = ' '))
		(m->c_num)++;
	if (pr && (pr != -2) && ((pr) == -1 ? (pr = 6) : 1))
		m->c_num += pr + 1;
	else if ((pr == -2 || pr == 0) && ft_strchr(m->flag, '#'))
		m->c_num++;
	(ft_strchr(m->flag, '0') && d < 0) ? ft_putchar('-') : 1;
	(ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	do_width(m, 'R');
	(!ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	(!ft_strchr(m->flag, '0') && d < 0) ? ft_putnbr(-ip) : ft_putnbr(ip);
	if (pr && (pr != -2) && write(1, ".", 1))
		P_PRECI;
	((pr == -2 || pr == 0) && ft_strchr(m->flag, '#')) ? ft_putchar('.') : 1;
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
