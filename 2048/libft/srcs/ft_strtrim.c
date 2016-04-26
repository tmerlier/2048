/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:58:54 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/27 13:59:09 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

int				ft_end(char *s, size_t i)
{
	size_t		end;

	end = i;
	while (s[i])
	{
		if (!ft_iswhite(s[i]))
			end = i;
		i++;
	}
	return (end);
}

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*sout;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_iswhite(s[i]) && s[i])
		i++;
	start = i;
	end = ft_end((char *)s, start);
	sout = (char *)malloc((end - start + 2) * sizeof(char));
	if (start != end || (start == end && start != ft_strlen(s)))
	{
		if (sout == NULL)
			return (NULL);
		ft_strncpy(sout, s + start, end - start + 1);
		sout[end - start + 1] = 0;
	}
	else if (start == end && start == ft_strlen(s))
		return (ft_strdup(""));
	return (sout);
}
