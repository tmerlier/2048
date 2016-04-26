/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:01:09 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:14:15 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <libft.h>
#include <game.h>

static void		put_digit(t_env *env, int value, int x, int y)
{
	int				i;

	i = -1;
	while (++i < env->ascii.size_h)
		mvprintw(y + i, x, env->ascii.nb[value][i]);
}

static void		put_number(t_env *env, int value, int x, int y)
{
	int			t;
	int			len;

	t = value;
	len = 1;
	while ((t = t / 10))
		len++;
	while (len--)
	{
		put_digit(env, value % 10, x + len * env->ascii.size_w, y);
		value = value / 10;
	}
}

void			put_ascii_middle(t_env *env, int value, int x, int y)
{
	int				len;
	int				t;
	int				i;

	t = value;
	len = env->ascii.size_w;
	while ((t = t / 10))
		len += env->ascii.size_w;
	i = -1;
	while (++i < env->ascii.size_h)
	{
		t = -1;
		while (++t < (env->cell_w - len) / 2)
			mvaddch(y + i, x + t, ' ');
	}
	put_number(env, value, x + t, y);
	len = x + t + len - 1;
	i = -1;
	while (++i < env->ascii.size_h)
	{
		t = len;
		while (++t < x + env->cell_w)
			mvaddch(y + i, t, ' ');
	}
}
