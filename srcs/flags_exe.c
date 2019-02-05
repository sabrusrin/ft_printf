/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/02/05 23:52:12 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_sup.h"

void	pf_putnbr(int n, t_mdfrs *mods)
{
	char fl;
	char sign;

	sign = 0;
	fl = ' ';
	if (ft_strchr(mods->flag, '0'))
			fl = '0';
	if (ft_strchr(mods->flag, '+') && (n > 0) && (sign = '+'))
		(mods->c_num)++;
	else if (ft_strchr(mods->flag, '+') && (n > 0) && (sign = ' '))
		(mods->c_num)++;
	if (!(ft_strchr(mods->flag, '-')) && (mods->width))
			while((mods->width)-- > mods->c_num)
				write(1, &fl, 1);
	if (sign)
		write(1, &sign, 1);
	ft_putnbr(n);
	if ((fl != '0') && ft_strchr(mods->flag, '-') && (mods->width))
		while((mods->width)-- > mods->c_num)
			write(1, &fl, 1);
}

int		pf_putdouble(double f)
{

}
