/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:32:56 by chermist          #+#    #+#             */
/*   Updated: 2019/02/06 20:32:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int		main(void)
{
	float	f;
	float	fpart;
	int		ipart;
	int		tmp;

	f = 3.141592;
	//printf("%d\n", (int)f);
	ipart = (int)f;

	ft_putnbr(ipart);
	write(1, "\n", 1);
	
	fpart = f - (float)ipart;
	printf("%f\n", fpart);
	ft_putnbr(ipart);
	write(1, "\n", 1);
	return (0);
}
