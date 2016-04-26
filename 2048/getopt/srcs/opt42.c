/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:22:51 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/04 16:23:12 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <getopt42.h>

t_opt42		*new_opt42(char s_name, char *l_name, char has_param, void *param)
{
	t_opt42				*new;

	new = (t_opt42 *)malloc(sizeof(t_opt42));
	new->s_name = s_name;
	new->l_name = l_name;
	new->has_param = has_param;
	new->param = param;
	new->next = NULL;
	return (new);
}

void		set_opt42(char s_name, char *l_name, char has_param, void *par)
{
	t_opt42			*new;

	new = new_opt42(s_name, l_name, has_param, par);
	new->next = g_opt42;
	g_opt42 = new;
}
