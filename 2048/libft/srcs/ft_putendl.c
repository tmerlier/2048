/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:04:54 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/25 17:40:37 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int			ft_putendl(char const *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)) + ft_putchar('\n'));
	return (0);
}
