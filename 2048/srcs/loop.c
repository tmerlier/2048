/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 01:22:12 by tmerlier          #+#    #+#             */
/*   Updated: 2015/03/01 23:40:08 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <game.h>

#include <libft.h>

static void		dup_plate(int **dest, int **src, int size)
{
	int				x;
	int				y;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			dest[x][y] = src[x][y];
	}
}

static int		exec_key(t_env *env, int key)
{
	int			ret_move;
	int			ret_end;

	if (key == 27)
		return (1);
	else if (key == KEY_UP || key == KEY_LEFT
			|| key == KEY_RIGHT || key == KEY_DOWN)
	{
		ret_move = move_plate(env, key);
		if (ret_move != -1)
		{
			env->score += ret_move;
			pop_new(env->plate, env->size);
		}
		ret_end = check_end(env);
		if (ret_end == -1)
			return (1);
	}
	else if (key == 'u' && env->undo-- > 0)
		dup_plate(env->plate, env->last_plate, env->size);
	else if (key == KEY_F(1))
		save_plate(env);
	else if (env->ascii.ascii_on && key >= '1' && key <= MAX_ASCII + '0')
		load_ascii(env, key - '0');
	return (0);
}

static int		test_window(t_env *env)
{
	if (env->ascii.ascii_on
			&& (env->h <= env->size * env->ascii.size_h
				|| env->w <= 4 * env->ascii.size_w * env->size))
		return (1);
	else if (env->h <= env->size || env->w <= 4 * env->size)
		return (1);
	return (0);
}

int				main_loop(t_env *env)
{
	int				key;
	int				ret_exec;

	set_winsize(env);
	if (env->load == 1)
		load_game(env);
	dup_plate(env->last_plate, env->plate, env->size);
	print_plate(env);
	while (refresh() == OK && (key = getch()) && clear() == OK)
	{
		if (key == KEY_RESIZE && (ret_exec = 0) == 0)
			set_winsize(env);
		if (test_window(env))
			mvprintw(1, 1, "Affichage impossible");
		else
		{
			dup_plate(env->last_plate, env->plate, env->size);
			if (key != KEY_RESIZE)
				ret_exec = exec_key(env, key);
			if (ret_exec != 0)
				return (ret_exec);
		}
		print_plate(env);
	}
	return (0);
}
