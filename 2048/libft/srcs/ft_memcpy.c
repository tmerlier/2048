/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:06:51 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 16:58:34 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int		index;

	index = 0;
	if ((size_t)(s2 - s1) < n || (s1 < s2 && s1 > s2 + n))
		return (s1);
	while (index < n)
	{
		*((char*)s1 + index) = *((char*)s2 + index);
		index++;
	}
	return (s1);
}
