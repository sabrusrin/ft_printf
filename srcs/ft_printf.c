/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:03:15 by chermist          #+#    #+#             */
/*   Updated: 2019/02/08 01:46:43 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include "../includes/ft_printf.h"

int		count_num(int i)
{
	static int	count = 0;

	count = 0;
	if ((i < 0) && (i *= -1))
		count++;
	if (i / 10 < 1)
		return (++count);
	count_num(i / 10);
	return (++count);
}

char	*parse_modifier(char *str, t_mdfrs *mods)
{
	int j;

	j = 0;
	mods->width = 0;
	while (FLAGS(*str) && (j < 5) && !(mods->flag[j + 1] = 0))
		mods->flag[j++] = *str++;
	while (ft_isdigit(*str))
		mods->width = (mods->width * 10) + (*str++ - '0');
	if (*str == '.' && (mods->preci-- && ft_isdigit(*(str + 1)) ?
				!(mods->preci = 0) : !(*str++)))
		while (ft_isdigit(*++str))
			mods->preci = (mods->preci * 10) + (*str - '0');
	if (MDFR(*str))
	{
		if (*str == 'l' && (*(str + 1) == 'l') && (str += 2))
			mods->modifier = "ll";
		else if (*str == 'h' && (*(str + 1) == 'h') && (str += 2))
			mods->modifier = "hh";
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
	int		i;

	i = 1;
	if (*spec == 'c')
		PF_CHAR(va_arg(ap, int));
	if (*spec == 'd' || *spec == 'i')
		pf_putnbr(va_arg(ap, int), mods);
	if (*spec == 'f' || *spec == 'F')
		pf_putdbl(va_arg(ap, double), mods);
	if (*spec == 's')
		mods->c_num = ft_putstr(va_arg(ap, char*));
	if (*spec == 'x' || *spec == 'X' || *spec == 'o')
		pf_base(va_arg(ap, int), mods);
	return (mods->c_num);
}

size_t	parse(const char *format, va_list ap)
{
	char	*str;
	size_t	i;
	t_mdfrs mods;

	str = (char*)format;
	i = 0;
	while (*str != '\0')
	{
		mods.preci = -1;
		mods.flag[0] = 0;
		mods.c_num = 0;
		while (*str != '%')
		{
			ft_putchar(*str);
			str++;
			i++;
			if (!(*str))
				return (i);
		}
		str++;
		if (!SPCFR(*str))
			str = parse_modifier(str, &mods);
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
