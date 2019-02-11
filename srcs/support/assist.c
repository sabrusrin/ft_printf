/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:07:47 by chermist          #+#    #+#             */
/*   Updated: 2019/02/11 18:18:42 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sup.h"

void	clean_mods(t_mdfrs *mods)
{
	int i;

	i = -1;
	while (++i < 6)
		mods->flag[i] = 0;
	mods->c_num = 0;
	mods->modifier[0] = 0;
	mods->modifier[1] = 0;
	mods->width = 0;
	mods->pr = -1;
	mods->spec = 0;
}

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
