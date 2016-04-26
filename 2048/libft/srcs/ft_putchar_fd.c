/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:23:57 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 16:59:52 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

int			ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		return (write(fd, &c, 1));
	return (-1);
}
