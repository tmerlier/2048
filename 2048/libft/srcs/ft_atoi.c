/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:47:45 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/13 11:59:46 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

int			ft_atoi(const char *s)
{
	int			nb;
	int			sign;
	size_t		i;

	sign = 1;
	i = 0;
	if (s == NULL)
		return (0);
	while (!ft_isprint(s[i]) || s[i] == '+' || s[i] == ' ')
		if (s[i++] == 0)
			return (0);
	if (*(s + i) == '-')
	{
		i++;
		sign = -1;
	}
	nb = 0;
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		nb *= 10;
		nb += *(s + i) - '0';
		i++;
	}
	return (nb * sign);
}
