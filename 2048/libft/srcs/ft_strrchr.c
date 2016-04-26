/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:04:30 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 11:27:51 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = ft_strlen(s);
	if (c == 0)
		return ((char *)s + size);
	while (i < size)
	{
		if (s[size - i] == (char)c)
			return ((char *)(s + (size - i)));
		i++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
