/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:08:46 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 20:58:34 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int			test_one_cell(int **plate, int x, int y, int size)
{
	int		ref;
	int		ret;

	ref = plate[x][y];
	ret = 0;
	if (x - 1 >= 0)
		ret += plate[x - 1][y] == ref ? 1 : 0;
	if (x + 1 < size)
		ret += plate[x + 1][y] == ref ? 1 : 0;
	if (y - 1 >= 0)
		ret += plate[x][y - 1] == ref ? 1 : 0;
	if (y + 1 < size)
		ret += plate[x][y + 1] == ref ? 1 : 0;
	return (ret);
}

static int			can_move(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->size)
	{
		x = -1;
		while (++x < env->size)
		{
			if (test_one_cell(env->plate, x, y, env->size) != 0)
				return (1);
		}
	}
	return (0);
}

static int			is_full(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->size)
	{
		x = -1;
		while (++x < env->size)
		{
			if (PLATE(x, y) == 0)
				return (0);
		}
	}
	return (1);
}

static int			has_win(t_env *env)
{
	int			x;
	int			y;
	int			t;

	t = WIN_VALUE;
	while (t != 2 && t != 1)
		t = t / 2;
	if (t == 2)
		t = WIN_VALUE;
	else
		t = DEFAULT_WIN_VALUE;
	y = -1;
	while (++y < env->size)
	{
		x = -1;
		while (++x < env->size)
			if (env->plate[x][y] == t)
				return (1);
	}
	return (0);
}

int					check_end(t_env *env)
{
	if (has_win(env) && !env->win)
		env->win = 1;
	if (is_full(env) && !can_move(env))
		return (-1);
	return (0);
}
