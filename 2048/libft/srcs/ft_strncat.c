/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:05:22 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:05:05 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		index;

	index = 0;
	while (s1[index])
		index++;
	while (n)
	{
		if (*s2 == '\0')
			n = 0;
		else
		{
			s1[index] = *s2;
			index++;
			n--;
			s2++;
		}
	}
	s1[index] = 0;
	return (s1);
}
