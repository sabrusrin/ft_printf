/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:16:57 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/18 23:16:55 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./ft_sup.h"

# define SPCFR(x) (ft_strchr("dDioOuUxXfeEcCsSpaAgGp", x))
# define FLAGS(x) (ft_strchr("-+ #0", x))
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)
# define ALLSHT(x) (ft_strchr("dDioOuUxXfeEcCsSpaAgGp-+ #0lLhjz.%", x))

size_t		parse(const char *format, va_list ap);

#endif
