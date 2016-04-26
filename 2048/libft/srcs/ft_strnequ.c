/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:41:52 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/27 14:00:44 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t		index;

	index = 0;
	if (!(s1 == NULL || s2 == NULL))
		while (*(s1 + index) == *(s2 + index) && index < n)
		{
			if (*(s1 + index) == 0)
				return (1);
			index++;
		}
	if (index == n)
		return (1);
	return (0);
}
