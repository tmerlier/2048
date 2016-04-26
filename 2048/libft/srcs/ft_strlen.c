/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:23:02 by rbernand          #+#    #+#             */
/*   Updated: 2014/02/28 19:49:44 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlen(const char *s)
{
	int			index;

	if (!s)
		return (0);
	index = 0;
	while (*(s + index))
		index++;
	return (index);
}
