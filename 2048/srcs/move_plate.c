/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:35:42 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 22:57:05 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <game.h>

static int		check_v_line(t_env *env, int x, int y, int dir)
{
	int			t;
	int			points;

	t = 1;
	points = 0;
	while (y + t * dir >= 0 && y + t * dir < env->size)
		if (PLATE(x, y + t * dir) == 0)
			t++;
		else if (PLATE(x, y + t * dir) == PLATE(x, y))
		{
			PLATE(x, y) *= 2;
			points += PLATE(x, y);
			env->has_move = 1;
			PLATE(x, y + t * dir) = 0;
			break ;
		}
		else if (PLATE(x, y + t * dir) != PLATE(x, y))
			break ;
	return (points);
}

static int		move_line_vertical(t_env *env, int dir)
{
	int			x;
	int			y;
	int			t;
	int			points;

	points = 0;
	x = -1;
	while (++x < env->size && (y = dir == 1 ? -1 : env->size) != -10)
		while ((y += dir) > -10 && y >= 0 && y < env->size)
			if (PLATE(x, y) != 0)
				points += check_v_line(env, x, y, dir);
			else if ((t = 1) == 1)
				while (y + t * dir >= 0 && y + t * dir < env->size)
					if (PLATE(x, y + t * dir) == 0)
						t++;
					else if ((env->has_move = 1) == 1)
					{
						PLATE(x, y) = PLATE(x, y + t * dir);
						PLATE(x, y + t * dir) = 0;
						y -= dir;
						break ;
					}
	return (env->has_move == 0 ? -1 : points);
}

static int		check_h_line(t_env *env, int x, int y, int dir)
{
	int			t;
	int			points;

	t = 1;
	points = 0;
	while (x + t * dir >= 0 && x + t * dir < env->size)
		if (PLATE(x + t * dir, y) == 0)
			t++;
		else if (PLATE(x + t * dir, y) == PLATE(x, y))
		{
			PLATE(x, y) *= 2;
			points += PLATE(x, y);
			env->has_move = 1;
			PLATE(x + t * dir, y) = 0;
			break ;
		}
		else if (PLATE(x + t * dir, y) != PLATE(x, y))
			break ;
	return (points);
}

static int		move_line_horizontal(t_env *env, int dir)
{
	int			x;
	int			y;
	int			t;
	int			points;

	points = 0;
	y = -1;
	while (++y < env->size && (x = dir == 1 ? -1 : env->size) != -10)
		while ((x += dir) > -10 && x >= 0 && x < env->size)
			if (PLATE(x, y) != 0)
				points += check_h_line(env, x, y, dir);
			else if ((t = 1) == 1)
				while (x + t * dir >= 0 && x + t * dir < env->size)
					if (PLATE(x + t * dir, y) == 0)
						t++;
					else if ((env->has_move = 1) == 1)
					{
						PLATE(x, y) = PLATE(x + t * dir, y);
						PLATE(x + t * dir, y) = 0;
						x -= dir;
						break ;
					}
	return (env->has_move == 0 ? -1 : points);
}

int				move_plate(t_env *env, int key)
{
	env->has_move = 0;
	if (key == KEY_LEFT)
		return (move_line_horizontal(env, 1));
	else if (key == KEY_RIGHT)
		return (move_line_horizontal(env, -1));
	else if (key == KEY_UP)
		return (move_line_vertical(env, 1));
	else if (key == KEY_DOWN)
		return (move_line_vertical(env, -1));
	return (0);
}
