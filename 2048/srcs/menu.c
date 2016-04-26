/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:06:16 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 22:55:10 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <game.h>

static void		print_middle(char *str, int w, int y, t_color c)
{
	attron(COLOR_PAIR(c));
	mvprintw(y, (w - ft_strlen(str)) / 2, str);
	attroff(COLOR_PAIR(c));
}

static void		print_head(int w)
{
	int				dec_w;
	int				fd;
	char			*line;
	int				i;

	dec_w = (w - INTRO_W) / 2;
	fd = open("./misc/intro", O_RDONLY);
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		mvprintw(2 + i++, dec_w, line);
		free(line);
		line = NULL;
	}
	close(fd);
}

static int		print(t_env *env, int cursor)
{
	int					dec_h;
	int					i;
	char				*list[5];

	if (env->w < 31 || env->h < 20)
	{
		mvprintw(2, 2, "Too small Trye again");
		return (1);
	}
	list[0] = "Play 2048";
	list[1] = "Load Game";
	list[2] = "Show Score";
	list[3] = "Why it is Better with Butter?";
	list[4] = "Exit";
	print_head(env->w);
	dec_h = INTRO_H + (env->h - INTRO_H) / 2 - 5;
	i = -1;
	while (++i < 5)
	{
		attron(i == cursor ? A_UNDERLINE : 0);
		print_middle(list[i], env->w, dec_h + 2 * i, cursor == i ? _n2 : _n128);
		attroff(i == cursor ? A_UNDERLINE : 0);
	}
	return (1);
}

static int		exec_key(t_env *env, t_menu cursor)
{
	if (cursor == _load)
		env->load = 1;
	if (cursor == _help)
		print_help();
	if (cursor == _score)
		dump_score(env);
	return (cursor);
}

t_menu			menu(t_env *env)
{
	int					key;
	int					ret_exec;
	t_menu				c;

	c = _play;
	wbkgd(stdscr, COLOR_PAIR(_WHITE));
	while (print(env, c) && refresh() == OK && (key = getch()) && clear() == OK)
	{
		if (key == KEY_RESIZE)
			set_winsize(env);
		if (env->w < 31 || env->h < 20)
			continue ;
		if (key == KEY_DOWN)
			c = c + 1 < 5 ? c + 1 : 4;
		else if (key == KEY_UP)
			c = c - 1 >= 0 ? c - 1 : 0;
		else if (key == '\n')
		{
			ret_exec = exec_key(env, c);
			if (ret_exec == _play || ret_exec == _load || ret_exec == _leave)
				return (ret_exec);
		}
	}
	return (0);
}
