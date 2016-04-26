/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:37:15 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 10:28:48 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strequ(const char *s1, const char *s2)
{
	size_t		index;

	index = 0;
	if (!(s1 == NULL || s2 == NULL))
		while (*(s1 + index) == *(s2 + index))
		{
			if (*(s1 + index) == 0)
				return (1);
			index++;
		}
	return (0);
}
