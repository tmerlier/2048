/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:14:27 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/06 11:23:36 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		index;

	index = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-(*s2));
	if (s2 == NULL)
		return (*s1);
	if (n == 0)
		return (0);
	while ((unsigned char)s1[index] == (unsigned char)s2[index])
	{
		n--;
		if (n == 0 || s1[index] == 0)
			return (0);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
