/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:00:30 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/24 20:30:03 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	l_ft_putchar(int c)
{
	int a;

	a = 0;
	if (c <= 127)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c <= 255)
	{
		a = ((c >> 6) | 0xC0);
		write(1, &a, 1);
		a = ((c & 0x3F) | 0x80);
		write(1, &a, 1);
		return (2);
	}
	return (more_bytes_putchar(c));
}

int	more_bytes_putchar(int c)
{
	int a;

	a = 0;
	if (c < 2048)
	{
		a = ((c >> 6) | 0xC0);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (2);
	}
	else if (c < 65536)
	{
		a = ((c >> 12) | 0xE0);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (3);
	}
	else if (c < 2097152)
	{
		a = ((c >> 18) | 0xF0);
		write(1, &a, 1);
		a = (((c >> 12) & 63) | 0x80);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (4);
	}
	return (-1);
}
