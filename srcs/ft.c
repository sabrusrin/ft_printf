/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:21:50 by chermist          #+#    #+#             */
/*   Updated: 2019/02/05 22:08:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sup.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	return (NULL);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
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

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char const *s)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s && ++count)
		ft_putchar(*s++);
	return (count);
}
