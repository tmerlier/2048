/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:27:31 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/21 17:07:59 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int			ft_putstr_fd(const char *str, int fd)
{
	if (str && fd != -1)
		return (write(fd, str, ft_strlen(str)));
	else if (!str)
		return (0);
	else
		return (-1);
}
