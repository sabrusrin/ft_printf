/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:13:19 by chermist          #+#    #+#             */
/*   Updated: 2019/02/20 22:04:35 by lkarlon-         ###   ########.fr       */
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
void			u_pf_putnbr(unsigned long long n, t_mdfrs *m);
void			pf_putdbl(long double d, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
double			ft_pow(double d, int pow);
void			do_width(t_mdfrs *m, char f);
void			do_hash(t_mdfrs *m, int f);
void			do_preci(t_mdfrs *m, long double dpart, char c);
void			nbr_preci(t_mdfrs *m, long long *n, char *sign);
void			nbr_sign(t_mdfrs *m, char *sign, long long *n, char *p);
void			type_parse(va_list ap, t_mdfrs *m, char flag);
//void			save_mdfr(char *str, t_mdfrs *m);
void			clean_mods(t_mdfrs *m);
int				count_num(long long i);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strchr(const char *s, int c);
void			ft_putnbr(long long n);
int				ft_isdigit(char c);
int				ft_putstr(char const *s);
void			ft_putchar(char c);
void			x_type_parse(va_list ap, t_mdfrs *m);
void			u_type_parse(va_list ap, t_mdfrs *m);
void			d_type_parse(va_list ap, t_mdfrs *m);
void			u_ft_putnbr(unsigned long long n);
int				u_count_num(unsigned long long i);

#endif
