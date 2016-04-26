/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:54:16 by caupetit          #+#    #+#             */
/*   Updated: 2014/03/27 13:55:25 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int				ft_get_arg_opt(char opt, va_list ap)
{
	int				i;
	int				nb_put;
	int				opt_tab[NB_OPT];
	static t_f		func[NB_OPT] =

	{
	ft_d,
	ft_d,
	ft_c,
	ft_s,
	ft_u,
	ft_o
	};
	nb_put = 0;
	i = -1;
	opt_tab[0] = 'd';
	opt_tab[1] = 'i';
	opt_tab[2] = 'c';
	opt_tab[3] = 's';
	opt_tab[4] = 'u';
	opt_tab[5] = 'o';
	while (++i < NB_OPT)
		if (opt_tab[i] == opt)
			nb_put += func[i](ap);
	return (nb_put);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			nb_put;

	i = -1;
	nb_put = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			nb_put += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i++;
			nb_put += ft_get_arg_opt(format[i], ap);
		}
	}
	va_end(ap);
	return (nb_put);
}
