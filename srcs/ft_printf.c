/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:03:15 by chermist          #+#    #+#             */
/*   Updated: 2019/02/17 13:36:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

char	*parse_modifier(char *str, t_mdfrs *mods)
{
	int j;

	j = 0;
	while (FLAGS(*str) && (j < 5) && !(mods->flag[j + 1] = 0))
		mods->flag[j++] = *str++;
	while (ft_isdigit(*str))
		mods->width = (mods->width * 10) + (*str++ - '0');
	if (*str == '.' && (mods->pr-- && ft_isdigit(*(str + 1)) ?
		!(mods->pr = 0) : !(*str++)))
		while (ft_isdigit(*++str))
			mods->pr = (mods->pr * 10) + (*str - '0');
	if (MDFR(*str))
	{
		if (*str == 'l' && (*(str + 1) == 'l') && (str += 2))
			ft_memcpy(mods->modifier, "ll", 2);
		else if (*str == 'h' && (*(str + 1) == 'h') && (str += 2))
			ft_memcpy(mods->modifier, "hh", 2);
		else
		{
			mods->modifier[0] = *str++;
			mods->modifier[1] = 0;
		}
	}
	mods->spec = *str;
	return (str);
}

size_t	spec_exe(char *spec, va_list ap, t_mdfrs *mods)
{
	if (*spec == 'c')
		pf_putchar(va_arg(ap, int), mods);
	if (*spec == 'd' || *spec == 'i')
	{
		if (mods->modifier[0] == 'l' && mods->modifier[1] == 'l')
			pf_putnbr(va_arg(ap, long long), mods);
		else if (mods->modifier[0] == 'l')
			pf_putnbr(va_arg(ap, long), mods);
		else
			pf_putnbr(va_arg(ap, int), mods);
	}
	if (*spec == 'u')
		pf_putnbr(va_arg(ap, unsigned int), mods);
	if (*spec == 'f' || *spec == 'F')
		(mods->modifier[0] == 'L') ?
		(pf_putdbl(va_arg(ap, long double), mods)) :
		(pf_putdbl(va_arg(ap, double), mods));
	if (*spec == 's')
		pf_putstr(va_arg(ap, char*), mods);
	if (*spec == 'x' || *spec == 'X' || *spec == 'o')
	{
		if (mods->modifier[0] == 'l' && mods->modifier[1] == 'l')
			pf_base(va_arg(ap, unsigned long long), mods);
		else if (mods->modifier[0] == 'l')
			pf_base(va_arg(ap, unsigned long), mods);
		else
			pf_base(va_arg(ap, unsigned int), mods);
	}
	if (*spec == '%')
		pf_putchar('%', mods);
	if (*spec == 'p' ? (mods->flag[0] = '#') : 0)
		(pf_base(va_arg(ap, long int), mods));
	return (mods->c_num);
}

size_t	parse(const char *format, va_list ap)
{
	char	*str;
	size_t	i;
	t_mdfrs mods;
	int		*count;

	str = (char*)format;
	i = 0;
	mods.c_num = 0;
	while (*str != '\0')
	{
		clean_mods(&mods);
		while (*str != '%' && ++i)
		{
			ft_putchar(*str++);
			if (!(*str))
				return (i);
		}
		str++;
		str = parse_modifier(str, &mods);
		if (*str == 'n' && (count = va_arg(ap, int*)))
			*count = i;
		i += spec_exe(str, ap, &mods);
		str++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		result;
	va_list ap;

	va_start(ap, format);
	result = parse(format, ap);
	va_end(ap);
	return (result);
}
