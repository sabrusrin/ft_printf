/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:16:57 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/02/17 16:28:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./ft_sup.h"

# define SPCFR(x) (ft_strchr("diouxXfeEcspaAgGp", x) != NULL)
# define FLAGS(x) (ft_strchr("-+ #0", x) != NULL)
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)
# define ALLSHT(x) (ft_strchr("diouxXfeEcspaAgGp-+ #0lLhjz.%", x)) 

#endif
