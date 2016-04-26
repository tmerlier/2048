/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:53:45 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 16:59:33 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t		index;

	index = 0;
	while (index < len)
	{
		*((char*)b + index) = c;
		index++;
	}
	return (b);
}
