/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:10:54 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/06 11:15:24 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-(*s2));
	if (s2 == NULL)
		return (*s1);
	while ((unsigned char)*(s1 + index) == (unsigned char)*(s2 + index))
	{
		if (*(s1 + index) == 0)
			return (0);
		index++;
	}
	return ((unsigned char)*(s1 + index) - (unsigned char)*(s2 + index));
}
