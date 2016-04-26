/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:12:26 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:04:23 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		index;

	index = 0;
	if (!(s == NULL || f == NULL))
		while (*(s + index))
		{
			f(index, s + index);
			index++;
		}
}
