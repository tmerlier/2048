/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:27:31 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/25 17:00:46 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

int		ft_putstr(const char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str)
		write(1, str, ft_strlen(str));
	return (len);
}
