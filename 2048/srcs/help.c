/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:16:13 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:16:20 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <game.h>

void		print_help(void)
{
	int			i;

	clear();
	i = 0;
	mvprintw(i++ * 2, 1, "\t-a --ascii\n\t\tPlay with ascii art\n");
	mvprintw(++i * 2, 1, "\t-h --help\n\t\tDisplay this message\n");
	mvprintw(++i * 2, 1,
			"\t-s --size\n\t\tSet the size of the game. Betwenn 4 and 30\n");
	mvprintw(++i * 2, 1, "\t-u --undo\n\t\tSet undo as available *u times\n");
	refresh();
	getch();
	clear();
}
