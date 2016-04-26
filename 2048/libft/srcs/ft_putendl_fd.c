/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:04:54 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/29 16:31:17 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int			ft_putendl_fd(char const *s, int fd)
{
	if (s && fd != -1)
		return (write(fd, s, ft_strlen(s)) + ft_putchar_fd('\n', fd));
	else if (!s)
		return (0);
	else
		return (-1);
}
