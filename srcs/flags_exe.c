/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/02/07 02:18:42 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_sup.h"

double	ft_pow(double d, int pow)
{
	return (pow ? (d * ft_pow(d, pow -1)) : 1);
}

void	pf_putnbr(int n, t_mdfrs *mods)
{
	char	fl;
	char	sign;
	int		c;

	c = 0;
	sign = 0;
	F_ZERO;
	if (ft_strchr(mods->flag, '+') && (n > 0) && (sign = '+'))
		(mods->c_num)++;
	else if (ft_strchr(mods->flag, '+') && (n > 0) && (sign = ' '))
		(mods->c_num)++;
	R_JUST;
	if (sign)
		write(1, &sign, 1);
	ft_putnbr(n);
	L_JUST;
	mods->c_num += c;
}

void	pf_putdouble(double d, t_mdfrs *mods)
{
	double	dpart;
	char	fl;
	int		ipart;
	int		c;
	int		i;

	c = 0;
	ipart = (int)d;
	i = count_num(ipart);
	dpart = d - (double)ipart;
	if (mods->preci && (mods->preci != -2))
		mods->c_num = mods->preci + 1 + i;
	else if ((mods->preci == -2) && ft_strchr(mods->flag, '#'))
		mods->c_num = i + 1;
	F_ZERO;
	R_JUST;
	ft_putnbr(ipart);
	if (mods->preci && (mods->preci != -2) && write(1, ".", 1))
	{
		(mods->preci) == -1 ? (mods->preci = 6) : 1;
		P_PRECI;
	}
	else if ((mods->preci == -2) && ft_strchr(mods->flag, '#'))
		ft_putchar('.');
	L_JUST;
	mods->c_num += c;
}
