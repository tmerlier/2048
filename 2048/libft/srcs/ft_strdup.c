/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:17:48 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/26 22:49:53 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;

	s2 = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		s2 = (char*)malloc((len + 1) * sizeof(char));
		ft_bzero(s2, len + 1);
		if (s2)
			ft_strcpy(s2, s1);
	}
	return (s2);
}
