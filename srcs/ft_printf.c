/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:03:15 by chermist          #+#    #+#             */
/*   Updated: 2019/02/04 23:16:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"

int		count_num(int i)
{
	static int	count = 0;

	count = 0;
	if (i / 10 < 1)
		return (++count);
	count_num(i / 10);
	return (++count);
}

int		convert(unsigned int num, int base, int x)
{
	char	*int_list;
	char	buffer[50];
	char	*ptr;

	if (x)
		int_list = "0123456789abcdef";
	else
		int_list = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = int_list[num % base];
		num /= base;
	}
	return (ft_putstr(ptr));
}

char	*parse_modifier(char *str, t_mdfrs mods)
{
	int j;

	j = 0;
	mods.width = 0;
	while (FLAGS(*str) && (j < 5) && (mods.flag[j + 1] = 0))
		mods.flag[j++] = *str++;
	while (ft_isdigit(*str))
		mods.width = (mods.width * 10) + (*str++ - '0');
	if (*str == '.')
		while (ft_isdigit(*++str))
			mods.precision = (mods.precision * 10) + (*str - '0');
	if (MDFR(*str))
	{
		if (*str == 'l' && (*(str + 1) == 'l') && (str += 2))
			mods.modifier = "ll";
		else if (*str == 'h' && (*(str + 1) == 'h') && (str += 2))
			mods.modifier = "hh";
		else
		{
			mods.modifier[0] = *str++;
			mods.modifier[1] = 0;
		}
	}
	return (str);
}

size_t	spec_exe(char *spec, va_list ap)
{
	int		i;

	i = 1;
	if (*spec == 'c')
		PF_CHAR(va_arg(ap, int));
	if (*spec == 'd' || *spec == 'i')
		PF_NBR(va_arg(ap, int));
	if (*spec == 's')
		PF_STR(va_arg(ap, char*));
	if (*spec == 'x')
		return (convert(va_arg(ap, int), 16, 1));
	if (*spec == 'X')
		return (convert(va_arg(ap, int), 16, 0));
	if (*spec == 'o')
		return (convert(va_arg(ap, int), 8, 1));
	return (0);
}

size_t	parse(const char *format, va_list ap)
{
	char	*str;
	size_t	i;
	t_mdfrs mods;

	str = (char*)format;
	mods.precision = 0;
	i = 0;
	while (*str != '\0')
	{
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
			str = parse_modifier(str, mods);
		i += spec_exe(str, ap);
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
