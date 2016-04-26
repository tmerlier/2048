/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:53:48 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 17:15:45 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <game.h>

static void		set_color(int value, char mode)
{
	int				value_bin;

	value_bin = _n2;
	while (value != 2)
	{
		value_bin++;
		value = value / 2;
	}
	if (mode == ON)
		attron(COLOR_PAIR(value_bin));
	else if (mode == OFF)
		attroff(COLOR_PAIR(value_bin));
}

static void		print_middle(int y, int x, int cell_w, int content)
{
	int			len;
	int			t;

	len = 0;
	t = content;
	while (t)
	{
		len++;
		t = t / 10;
	}
	t = -1;
	while (++t < (cell_w - len) / 2)
		mvaddch(y, x + t, ' ');
	printw("%d", content);
	t += len - 1;
	while (++t < cell_w)
		mvaddch(y, x + t, ' ');
}

static void		print_cell(t_env *env, int y, int x, int content)
{
	int				h;
	int				w;

	if (content == 0)
		return ;
	set_color(content, ON);
	h = -1;
	while (((env->ascii.ascii_on && ++h < (env->cell_h - env->ascii.size_h) / 2)
			|| (!env->ascii.ascii_on && ++h < env->cell_h / 2))
				&& (w = -1) == -1)
		while (++w < env->cell_w)
			mvwaddch(stdscr, y + h, x + w, ' ');
	if (!env->ascii.ascii_on)
		print_middle(y + h, x, env->cell_w, content);
	else
	{
		put_ascii_middle(env, content, x, y + h);
		h += env->ascii.size_h - 1;
	}
	while (++h < env->cell_h && (w = -1) == -1)
		while (++w < env->cell_w)
			mvaddch(y + h, x + w, ' ');
	set_color(content, OFF);
}

static void		print_ath(t_env *env)
{
	int				i;
	int				score_len;
	int				t;

	t = WIN_VALUE;
	while (t != 2 && t != 1)
		t = t / 2;
	if (t == 2)
		t = WIN_VALUE;
	else
		t = DEFAULT_WIN_VALUE;
	score_len = 10;
	i = env->score;
	while ((i = i / 10))
		score_len++;
	mvprintw(env->h - 1, env->w - score_len, "Score : %d", env->score);
	if (!env->win)
		mvprintw(env->h - 1, 1, "GOAL : %d", t);
	else
		mvprintw(env->h - 1, 1, "GOAL : ACHIEVED! YOU WON!");
}

void			print_plate(t_env *env)
{
	int				x;
	int				y;

	env->cell_h = (env->h - 1) / env->size;
	env->cell_w = env->w / env->size;
	wbkgd(stdscr, COLOR_PAIR(_WHITE));
	x = -1;
	while (++x < env->size)
	{
		y = -1;
		while (++y < env->size)
			print_cell(env, y * env->cell_h, x * env->cell_w, env->plate[x][y]);
	}
	print_ath(env);
}
