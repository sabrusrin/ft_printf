/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:21:50 by chermist          #+#    #+#             */
/*   Updated: 2019/02/26 22:39:14 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
		((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}

int		ft_putstr(char const *s)
{
	int count;
	int final;

	count = 0;
	final = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count = ft_putchar((int)*s);
		s += count;
		final += count;
	}
	return (final);
}

int		l_ft_putstr(int *s)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count += l_ft_putchar(*s);
		s++;
	}
	return (count);
}

void	ft_putnbr(long long n)
{
	if (n == INT64_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	u_ft_putnbr(unsigned long long n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
