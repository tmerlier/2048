/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:43:45 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 12:10:17 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		index;
	char				*snew;

	snew = NULL;
	if (!(s == NULL || f == NULL))
		snew = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!snew)
		return (NULL);
	index = 0;
	while (*(s + index))
	{
		*(snew + index) = f(index, *(s + index));
		index++;
	}
	return (snew);
}
