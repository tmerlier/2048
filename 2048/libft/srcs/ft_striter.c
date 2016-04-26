/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:01:02 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:04:14 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void		ft_striter(char *s, void (*f)(char*))
{
	int		index;

	index = 0;
	if (!(s == NULL || f == NULL))
		while (*(s + index))
		{
			f(s + index);
			index++;
		}
}
