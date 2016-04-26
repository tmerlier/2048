/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:26:29 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 17:06:07 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (*to_find == 0)
		return ((char*)str);
	while (*(str + i))
	{
		j = 0;
		while (*(str + i + j) == *(to_find + j))
		{
			if (*(to_find + j + 1) == 0)
				return ((char*)(str + i));
			else
				j++;
		}
		i++;
	}
	return (NULL);
}
