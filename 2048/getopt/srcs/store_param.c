/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:19:37 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/04 16:38:48 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <getopt42.h>

char		store_l_param(t_opt42 *opt, t_argv42 *arg)
{
	if (opt->has_param)
	{
		if (arg->next == NULL || arg->next->is_opt)
		{
			ft_putendl("Missing argument");
			return (-1);
		}
		*((char **)opt->param) = (char *)ft_strdup(arg->next->str);
		arg->next->is_param = 1;
	}
	else
		*((char *)opt->param) += 1;
	return (opt->has_param);
}

char		store_s_param(t_opt42 *opt, t_argv42 *arg)
{
	if (opt->has_param)
	{
		if (arg->next == NULL || arg->next->is_opt)
		{
			ft_putendl("Missing argument");
			return (-1);
		}
		if (ft_strlen(arg->str) != 2)
		{
			ft_putendl("too many parameters");
			return (-1);
		}
		*((char **)opt->param) = (char *)ft_strdup(arg->next->str);
		arg->next->is_param = 1;
	}
	else
		*((char *)opt->param) += 1;
	return (opt->has_param);
}
