/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:29:23 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:05:46 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (*s2 == 0)
		return ((char*)s1);
	i = 0;
	while (i < n && *(s1 + i))
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j) && i + j < n)
		{
			if (*(s2 + j + 1) == 0)
				return ((char*)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
