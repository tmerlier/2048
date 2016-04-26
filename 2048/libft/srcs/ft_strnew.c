/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:47:50 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 11:26:50 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc(size * sizeof(char) + 1);
	if (s)
		ft_bzero(s, size + 1);
	return (s);
}
