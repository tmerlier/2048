/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:52:46 by tmerlier          #+#    #+#             */
/*   Updated: 2015/03/01 22:33:37 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <libft.h>
#include <game.h>

static void			new_record(t_env *env, char *login)
{
	print_plate(env);
	if (SCORE(MAX_SCORE - 1) > env->score)
	{
		mvprintw(env->h / 2 - 2, env->w / 2 - 10, "Score %d", env->score);
		mvprintw(env->h / 2 - 1, env->w / 2 - 10, "Press to quit");
		return ;
	}
	echo();
	move(env->h / 2 - 1, env->w / 2 - 10);
	if (env->win)
		printw("You win ! Enter your name");
	else
		printw("You loose ! Enter your name");
	move(env->h / 2, env->w / 2 - 7);
	ft_bzero(login, 21);
}

void				save_score(t_env *env)
{
	char		login[21];
	int			fd;
	int			i;

	new_record(env, login);
	wgetnstr(stdscr, login, 20);
	if (login[0] == 0)
		return ;
	if ((fd = open(".scoreboard", O_WRONLY | O_CREAT, S_IRWXU)) == -1)
		exit(0);
	if (SCORE(MAX_SCORE - 1) <= env->score)
	{
		SCORE(MAX_SCORE - 1) = env->score;
		PLAYER(MAX_SCORE - 1) = ft_strdup(login);
	}
	i = -1;
	while (++i < MAX_SCORE)
	{
		if (PLAYER(i) == NULL)
			continue ;
		ft_putendl_fd(env->scoreboard[i].player, fd);
		ft_putnbr_fd(SCORE(i), fd);
		ft_putchar_fd('\n', fd);
	}
	close(fd);
}
