/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 01:49:33 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:16:58 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qdel(t_q **q)
{
	if (q && *q)
	{
		ft_memdel(&(*q)->data);
		ft_memdel((void**)q);
	}
}
