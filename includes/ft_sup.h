/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:11:28 by chermist          #+#    #+#             */
/*   Updated: 2019/02/16 20:51:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUP_H
# define FT_SUP_H
# include "./ft_printf.h"

typedef struct	s_mdfrs
{
	char		flag[6];
	char		modifier[2];
	int			width;
	int			pr;
	char		spec;
	int			c_num;
}				t_mdfrs;

void			pf_putchar(char c, t_mdfrs *m);
void			pf_putstr(char	*s, t_mdfrs *m);
void			pf_putnbr(long long n, t_mdfrs *m);
void			pf_putdbl(long double d, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
double			ft_pow(double d, int pow);
void			do_width(t_mdfrs *m, char f);
void			do_hash(t_mdfrs *m, int f);
void			do_preci(t_mdfrs *m, long double dpart, char c);
void			clean_mods(t_mdfrs *mods);
int				count_num(long long i);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
void			ft_putnbr(long long n);
int				ft_isdigit(int c);
int				ft_putstr(char const *s);
void			ft_putchar(char c);

#endif
