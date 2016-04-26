/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:50:42 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:05:18 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		index;
	int			mem;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (s1);
	mem = 0;
	index = 0;
	while (index < n)
	{
		if (mem == 0)
			*(s1 + index) = *(s2 + index);
		else if (mem == 1)
			*(s1 + index) = 0;
		if (*(s2 + index) == 0)
			mem = 1;
		index++;
	}
	return (s1);
}
