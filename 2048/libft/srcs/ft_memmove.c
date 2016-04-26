/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:47:47 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/21 18:01:13 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	void		*st;

	st = (void *)malloc(n * sizeof(char));
	if (st == NULL)
		return (NULL);
	ft_memcpy(st, s2, n);
	ft_memcpy(s1, st, n);
	free(st);
	return (s1);
}
