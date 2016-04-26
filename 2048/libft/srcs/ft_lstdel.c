/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:31:57 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/29 16:21:35 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <libft.h>

void	ft_lstdel(t_list **alst)
{
	t_list		*elem;
	t_list		*tnext;

	elem = *alst;
	while (elem)
	{
		tnext = elem->next;
		ft_strdel((char **)&(elem->content));
		elem = tnext;
	}
	*alst = NULL;
}
