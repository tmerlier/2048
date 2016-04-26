/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:07:23 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:03:16 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char		*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	return (NULL);
}
