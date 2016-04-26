/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:50:45 by rbernand          #+#    #+#             */
/*   Updated: 2014/02/28 19:50:55 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strcjoin(char *s1, char *s2, char c)
{
	char		*sout;
	int			lens1;
	int			lens2;

	lens1 = 0;
	lens2 = 0;
	if (s1)
		lens1 = ft_strlen(s1);
	if (s2)
		lens2 = ft_strlen(s2);
	sout = (char *)malloc(lens1 + lens2 + 2);
	ft_strcpy(sout, s1);
	sout[lens1] = c;
	ft_strcpy(sout + lens1 + 1, s2);
	sout[lens1 + lens2 + 1] = 0;
	return (sout);
}
