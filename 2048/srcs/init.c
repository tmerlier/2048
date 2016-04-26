/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 22:12:23 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 19:45:36 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <ncurses.h>
#include <getopt42.h>
#include <libft.h>
#include <game.h>

static void			init_opt(t_env *env, int *argc, char ***argv)
{
	int				help;

	help = 0;
	set_opt42('a', "ascii", 0, &env->ascii.ascii_on);
	set_opt42('h', "help", 0, &help);
	set_opt42('s', "size", 1, &env->tsize);
	set_opt42('u', "undo", 0, &env->undo);
	parse_opt42(*argc, *argv);
	shift_arg(argc, argv);
	if (help > 0)
	{
		print_usage((*argv)[0]);
		exit(-1);
	}
	if (env->tsize == NULL)
		env->size = DEFAULT_SIZE;
	else
	{
		env->size = ft_atoi(env->tsize);
		env->size = env->size < 4 ? 4 : env->size;
		env->size = env->size > 30 ? 30 : env->size;
		free(env->tsize);
	}
}

static void			init_game(t_env *env)
{
	int			i;

	init_scoreboard(env);
	if ((env->plate = (int **)malloc(sizeof(int *) * env->size)) == NULL)
		exit(0);
	if ((env->last_plate = (int **)malloc(sizeof(int *) * env->size)) == NULL)
		exit(0);
	i = -1;
	while (++i < env->size)
	{
		if ((env->plate[i] = (int *)ft_memalloc(sizeof(int) * env->size)) == 0)
			exit(0);
		if ((env->last_plate[i] =
					(int *)ft_memalloc(sizeof(int) * env->size)) == 0)
			exit(0);
	}
	pop_new(env->plate, env->size);
	pop_new(env->plate, env->size);
	set_winsize(env);
}

static void			init_ncurses_color(void)
{
	init_color(_n2, 230 * 4, 226 * 4, 175 * 4);
	init_color(_n4, 167 * 4, 123 * 4, 126 * 4);
	init_color(_n8, 239 * 4, 236 * 4, 202 * 4);
	init_color(_n16, 4 * 4, 99 * 4, 128 * 4);
	init_color(_n32, 0 * 4, 47 * 4, 47 * 4);
	init_color(_n64, 70 * 4, 137 * 4, 102 * 4);
	init_color(_n256, 70 * 4, 197 * 4, 82 * 4);
	init_color(_n128, 250 * 4, 240 * 4, 165 * 4);
	init_color(_n512, 250 * 4, 176 * 4, 59 * 4);
	init_color(_n1024, 182 * 4, 73 * 4, 38 * 4);
	init_color(_n2048, 142 * 4, 40 * 4, 0 * 4);
	init_pair(_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(_n2, COLOR_BLACK, _n2);
	init_pair(_n4, COLOR_BLACK, _n4);
	init_pair(_n8, COLOR_BLACK, _n8);
	init_pair(_n16, COLOR_WHITE, _n16);
	init_pair(_n32, COLOR_WHITE, _n32);
	init_pair(_n64, COLOR_WHITE, _n64);
	init_pair(_n128, COLOR_BLACK, _n128);
	init_pair(_n256, COLOR_BLACK, _n256);
	init_pair(_n512, COLOR_BLACK, _n512);
	init_pair(_n1024, COLOR_WHITE, _n1024);
	init_pair(_n2048, COLOR_WHITE, _n2048);
}

static void			init_ncurses(t_env *env)
{
	(void)env;
	initscr();
	srand(time(NULL));
	noecho();
	curs_set(0);
	start_color();
	init_ncurses_color();
	nodelay(stdscr, FALSE);
	keypad(stdscr, TRUE);
}

void				main_init(t_env *env, int *argc, char ***argv)
{
	int					i;

	env->tsize = NULL;
	env->score = 0;
	env->undo = 0;
	env->ascii.ascii_on = 0;
	env->win = 0;
	env->load = 0;
	i = -1;
	while (++i < MAX_SCORE)
	{
		env->scoreboard[i].player = NULL;
		env->scoreboard[i].score = 0;
	}
	init_opt(env, argc, argv);
	load_ascii(env, 2);
	init_ncurses(env);
	init_game(env);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigint);
}
