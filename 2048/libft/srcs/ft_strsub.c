/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:19:56 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 12:11:39 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t		max;
	size_t		index;
	char		*sout;

	if (s == NULL)
		return (NULL);
	max = ft_strlen(s);
	if (start + len > max || len == 0)
		return (ft_strdup(""));
	sout = (char *)malloc((len + 1) * sizeof(char));
	if (!sout)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		*(sout + index) = *(s + start + index);
		index++;
	}
	*(sout + len) = 0;
	return (sout);
}
