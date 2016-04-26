/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:37:35 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 11:24:57 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	s = (void *)malloc(size * sizeof(char));
	if (s)
		ft_bzero(s, size);
	return (s);
}
