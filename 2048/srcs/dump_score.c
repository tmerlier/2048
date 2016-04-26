/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:00:51 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 22:11:59 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <libft.h>
#include <game.h>

void			dump_score(t_env *env)
{
	int				i;

	i = -1;
	clear();
	mvprintw((env->h - MAX_SCORE) / 2 - 1,
				(env->w - 10) / 2,
				"BEST SCORE");
	while (++i < MAX_SCORE)
	{
		if (!PLAYER(i))
			continue ;
		attron(COLOR_PAIR(i + 101));
		mvprintw((env->h - MAX_SCORE) / 2 + i,
				(env->w - ft_strlen(PLAYER(i)) - 8) / 2,
				"%s - %d", PLAYER(i), SCORE(i));
		attroff(COLOR_PAIR(i + 101));
	}
	refresh();
	getch();
	clear();
}
