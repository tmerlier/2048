/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 12:13:44 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/04 16:38:53 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <getopt42.h>

extern t_opt42		*g_opt42;
extern t_argv42		*g_argv42;

char		parse_s_name(t_argv42 *arg)
{
	t_opt42			*tmp;
	int				i;

	i = 0;
	while ((arg->str)[++i])
	{
		tmp = g_opt42;
		while (tmp)
		{
			if (tmp->s_name == arg->str[i])
			{
				if (store_s_param(tmp, arg) == -1)
					exit(-1);
				break ;
			}
			tmp = tmp->next;
		}
		if (tmp == NULL)
		{
			ft_putendl("Wrong short parameter");
			return (-1);
		}
	}
	return (tmp->has_param);
}

char		parse_l_name(t_argv42 *arg)
{
	t_opt42			*tmp;

	tmp = g_opt42;
	while (tmp)
	{
		if (ft_strequ(arg->str + 2, tmp->l_name))
		{
			return (store_l_param(tmp, arg));
		}
		tmp = tmp->next;
	}
	ft_putendl_fd("Wrong long parameter", 2);
	return (-1);
}

void		shift_arg(int *argc, char ***argv)
{
	int				i;
	t_argv42		*tmp;

	i = 0;
	(void)argv;
	tmp = g_argv42;
	while (tmp)
	{
		if (!(tmp->is_param || tmp->is_opt))
			i++;
		tmp = tmp->next;
	}
	*argc = i;
	*argv = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = g_argv42;
	while (tmp)
	{
		if (!(tmp->is_param || tmp->is_opt))
			(*argv)[i++] = tmp->str;
		tmp = tmp->next;
	}
	(*argv)[i] = NULL;
}

int			end_opt(t_argv42 *tmp)
{
	if (*(tmp->str + 2) == 0)
	{
		tmp = tmp->next;
		while (tmp)
		{
			tmp->is_opt = 0;
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

void		parse_opt42(int argc, char **argv)
{
	int			ret;
	t_argv42	*tmp;

	init_argv(argc, argv);
	tmp = g_argv42;
	while (tmp)
	{
		if (*(tmp->str) == '-')
		{
			if (*(tmp->str + 1) == '-')
			{
				if (end_opt(tmp))
					break ;
				ret = parse_l_name(tmp);
			}
			else
				ret = parse_s_name(tmp);
			if (ret == -1)
				exit(-1);
			else if (ret == 1)
				tmp = tmp->next;
		}
		tmp = tmp == NULL ? tmp : tmp->next;
	}
	return ;
}
