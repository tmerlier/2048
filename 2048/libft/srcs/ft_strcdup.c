/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:08:42 by rbernand          #+#    #+#             */
/*   Updated: 2014/02/11 08:59:06 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

char		*ft_strcdup(const char *s, char c)
{
	char	*sout;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(sout = (char *)malloc(++i * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		sout[i] = s[i];
		i++;
	}
	sout[i] = 0;
	return (sout);
}
