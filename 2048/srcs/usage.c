/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:25:35 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:16:48 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <libft.h>
#include <game.h>

void		print_usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putendl(" [-ahsu]");
	ft_putendl("\t-a --ascii\n\t\tPlay with ascii art\n");
	ft_putendl("\t-h --help\n\t\tDisplay this message\n");
	ft_putendl("\t-s --size\n\t\tSet the size of the game. Betwenn 4 and 30\n");
	ft_putendl("\t-u --undo\n\t\tSet undo as available *u times\n");
}
