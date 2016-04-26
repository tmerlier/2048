/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:23:37 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 11:26:18 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strmap(const char *s, char (*f)(char))
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
		*(snew + index) = f(*(s + index));
		index++;
	}
	return (snew);
}
