/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:11:47 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/06 11:17:58 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;

	index = 0;
	if (!s)
		return (NULL);
	if (c > 255)
		return (NULL);
	while (index < n)
	{
		if ((unsigned char)c == *((unsigned char*)s + index))
			return ((unsigned char*)s + index);
		index++;
	}
	return (NULL);
}
