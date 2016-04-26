/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:48:43 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/11 17:30:18 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*tmp;

	if (new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		new->next = NULL;
	}
}
