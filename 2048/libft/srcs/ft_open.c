/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:29:27 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/21 18:37:49 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>

int		ft_open(char *name, int opt)
{
	int		fd;

	if (name)
	{
		if ((fd = open(name, opt)) == -1)
		{
			ft_putendl("Open Failed");
			return (-1);
		}
		else
			return (fd);
	}
	ft_putendl("File name null.");
	return (-1);
}
