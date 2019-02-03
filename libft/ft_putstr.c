/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:50:16 by chermist          #+#    #+#             */
/*   Updated: 2019/01/31 20:37:23 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putstr(char const *s)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s && ++count)
		ft_putchar(*s++);
	return (count);
}
