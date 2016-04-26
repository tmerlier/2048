/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:32:03 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:00:19 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_putnbr(int nb)
{
	long		n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		return (ft_putchar(n + '0'));
	else
		return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
}
