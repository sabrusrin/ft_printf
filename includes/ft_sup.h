/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:13:19 by chermist          #+#    #+#             */
/*   Updated: 2019/02/05 22:03:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUP_H
# define FT_SUP_H
# include "ft_printf.h"

typedef struct	s_mdfrs
{
	char	flag[6];
	char	*modifier;
	int		width;
	int		precision;
	char	spec;
	int		c_num;
}				t_mdfrs;

char	*ft_strchr(const char *s, int c);
void	pf_putnbr(int n, t_mdfrs *mods);
void    ft_putnbr(int n);
int     ft_isdigit(int c);
int     ft_putstr(char const *s);
void    ft_putchar(char c);

#endif
