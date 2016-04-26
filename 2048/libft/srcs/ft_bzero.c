/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:53:45 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 16:55:45 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		ft_bzero(void *s, size_t n)
{
	size_t		index;

	index = 0;
	if (s != NULL)
	{
		while (index < n)
		{
			*((char *)s + index) = 0;
			index++;
		}
	}
}
