/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:50:23 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/30 23:26:24 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			index;

	if ((size_t)(s2 - s1) < n || (s1 < s2 && s1 > s2 + n))
		return (s1);
	index = 0;
	while (index < n)
	{
		*((char*)s1 + index) = *((char*)s2 + index);
		if (*((char*)s2 + index) == c)
			return ((char*)s1 + index + 1);
		index++;
	}
	return (NULL);
}
