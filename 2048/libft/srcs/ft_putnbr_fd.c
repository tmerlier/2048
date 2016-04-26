/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:32:03 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:02:37 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_putnbr_fd(int nb, int fd)
{
	long		n;

	n = nb;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	else
		return (ft_putnbr_fd(n / 10, fd) + ft_putchar_fd(n % 10 + '0', fd));
}
