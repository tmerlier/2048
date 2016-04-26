/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:21:22 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/04 16:23:23 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <getopt42.h>

t_argv42	*new_argv42(char *str)
{
	t_argv42			*new;

	new = (t_argv42 *)malloc(sizeof(t_argv42));
	new->str = str;
	new->is_param = 0;
	new->is_opt = 0;
	if (*str == '-')
		new->is_opt = 1;
	new->next = NULL;
	return (new);
}

void		add_argv(char *str)
{
	static t_argv42		*last;

	if (last == NULL)
	{
		g_argv42 = new_argv42(str);
		last = g_argv42;
	}
	else
	{
		last->next = new_argv42(str);
		last = last->next;
	}
}

void		init_argv(int argc, char **argv)
{
	int			i;

	i = 0;
	while (i < argc)
		add_argv(argv[i++]);
}
