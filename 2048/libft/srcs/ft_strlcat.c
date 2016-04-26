/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:58:55 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/16 13:56:18 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		lendst;
	size_t		lensrc;
	size_t		j;

	if (dst == NULL)
		return (size);
	lendst = ft_strlen(dst);
	if (src == NULL)
		return (lendst);
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lendst);
	if (lendst > size)
		return (size + lensrc);
	j = 0;
	while ((lendst + j < size - 1) && src[j] != 0)
	{
		dst[lendst + j] = src[j];
		j++;
	}
	dst[lendst + j] = 0;
	return (lensrc + lendst);
}
