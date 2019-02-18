/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:07:47 by chermist          #+#    #+#             */
/*   Updated: 2019/02/18 22:59:36 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"

void	clean_mods(t_mdfrs *m)
{
	int i;

	i = -1;
	while (++i < 6)
		m->flag[i] = 0;
	m->c_num = 0;
	m->modifier[0] = 0;
	m->modifier[1] = 0;
	m->width = 0;
	m->pr = -1;
	m->spec = 0;
}

int		count_num(long long i)
{
	static int	count = 0;

	count = 0;
	if ((i < 0) && (i = -i))
		count++;
	while (i / 10 > 0)
	{
		++count;
		i /= 10;
	}
	return (++count);
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

double	ft_pow(double d, int pow)
{
	return (pow ? (d * ft_pow(d, pow - 1)) : 1);
}
