/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:53:43 by rbernand          #+#    #+#             */
/*   Updated: 2014/03/26 22:51:59 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		ft_bzero(*as, ft_strlen(*as));
		free(*as);
		*as = NULL;
	}
}
