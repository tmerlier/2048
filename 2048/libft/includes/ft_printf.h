/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:00:29 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 17:50:26 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# define NB_OPT 6

typedef int		(*t_f)(va_list);

int				ft_s(va_list ap);
int				ft_c(va_list ap);
int				ft_d(va_list ap);
int				ft_u(va_list ap);
int				ft_o(va_list ap);

#endif
