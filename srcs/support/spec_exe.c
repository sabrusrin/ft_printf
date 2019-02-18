/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:04 by chermist          #+#    #+#             */
/*   Updated: 2019/02/18 22:05:20 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/ft_sup.h"

void	pf_putchar(char c, t_mdfrs *m)
{
	m->c_num++;
	do_width(m, 'R');
	ft_putchar(c);
	do_width(m, 'L');
}

void	pf_putstr(char *s, t_mdfrs *m)
{
	char	*tmp;

	tmp = s;
	if ((s == NULL) ? (s = "(null)") : 0)
		m->c_num = 6;
	else if (*s)
	{
		while (*tmp++)
			m->c_num++;
		if ((!m->pr || m->pr == -2) ? (m->pr = -2) : 0)
			s = 0;
		else if (m->pr > 0 && (m->pr < m->c_num))
		{
			tmp = malloc(m->pr + 1);
			tmp[m->pr] = 0;
			ft_memcpy(tmp, s, m->pr);
			s = tmp;
			m->c_num = m->pr;
		}
	}
	do_width(m, 'R');
	ft_putstr(s);
	do_width(m, 'L');
	(*s && m->pr > 0 && (m->pr < m->c_num)) ? free(tmp) : 1;
}

void	pf_putnbr(long long n, t_mdfrs *m)
{
	char	sign;
	char	*p;

	sign = 0;
	m->c_num = count_num(n);
	p = ft_strchr(m->flag, '0');
	nbr_sign(m, &sign, &n, p);
	if (m->pr != -1 && (p ? (*p = 'z') : 1))
		nbr_preci(m, &n, &sign);
	if (m->pr == -1)
		(sign) ? write(1, &sign, 1) : 1;
	(m->pr == 0 && n == 0 && m->width != 0) ? m->width++ : 1;
	do_width(m, 'R');
	if (m->pr != -1)
		(sign) ? write(1, &sign, 1) : 1;
	(m->pr > 0) ? do_preci(m, 1.1, 'o') : 1;
	(m->pr == 0 && n == 0) ? 0 : ft_putnbr(n);
	(m->pr == 0 && n == 0 && m->width == 0) ? m->c_num-- : 1;
	do_width(m, 'L');
}

void	pf_putdbl(long double d, t_mdfrs *m)
{
	long double	dpart;
	long		ip;
	char		sign;

	sign = 0;
	ip = (long)(d < 0) ? -d : d;
	m->c_num = count_num(ip) + ((d < 0) ? 1 : 0);
	dpart = ((d < 0) ? -d : d) - ip;
	if (ft_strchr(m->flag, '+') && (d > 0) && (sign = '+'))
		(m->c_num)++;
	else if (ft_strchr(m->flag, ' ') && (d > 0) && (sign = ' '))
		(m->c_num)++;
	if (m->pr && (m->pr != -2) && ((m->pr) == -1 ? (m->pr = 6) : 1))
		m->c_num += m->pr + 1;
	else if ((m->pr == -2 || m->pr == 0) && ft_strchr(m->flag, '#'))
		m->c_num++;
	(ft_strchr(m->flag, '0') && d < 0) ? ft_putchar('-') : 1;
	(ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	do_width(m, 'R');
	(!ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	(!ft_strchr(m->flag, '0') && d < 0) ? ft_putnbr(-ip) : ft_putnbr(ip);
	if (m->pr && (m->pr != -2) && write(1, ".", 1))
		do_preci(m, dpart, 'f');
	((m->pr == -2 || !m->pr) && ft_strchr(m->flag, '#')) ? ft_putchar('.') : 1;
	do_width(m, 'L');
}

void	pf_base(uintmax_t num, t_mdfrs *m)
{
	char					*int_list;
	char					buffer[50];
	char					*ptr;
	int						base;

	(m->spec == 'X' || m->spec == 'x' || m->spec == 'p') ? (base = 16) : 1;
	(m->spec == 'o' || m->spec == 'O') ? (base = 8) : 1;
	(m->spec == 'X') ? (int_list = "0123456789ABCDEF") :
		(int_list = "0123456789abcdef");
	ptr = &buffer[49];
	*ptr = '\0';
	if (!num && ++m->c_num)
		ptr = "0";
	while (num != 0 && ++m->c_num && (*--ptr = int_list[num % base]))
		num /= base;
	if ((m->pr == -2 || m->pr == 0) && *ptr == '0' && (ptr = ""))
		m->c_num = 0;
	(m->spec == 'o' && m->c_num < m->pr && (m->pr = m->pr - m->c_num)) ?
		(m->c_num += m->pr) : 1;
	(ft_strchr(m->flag, '#') && m->pr <= 0) ? do_hash(m, 0) : 1;
	do_width(m, 'R');
	(ft_strchr(m->flag, '#') && m->pr <= 0) ? do_hash(m, 1) : 1;
	(m->spec == 'o' && m->pr > 0) ? do_preci(m, 1.1, 'o') : 1;
	ft_putstr(ptr);
	do_width(m, 'L');
}
