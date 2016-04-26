/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:30:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/03/01 22:33:15 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <game.h>

static int		is_sorted(t_env *env)
{
	int				i;

	i = -1;
	while (++i < MAX_SCORE - 1)
	{
		if (SCORE(i) < SCORE(i + 1))
			return (0);
	}
	return (1);
}

static void		sort_score(t_env *env)
{
	int					t;
	int					i;
	char				*name;

	while (!is_sorted(env))
	{
		i = -1;
		while (++i < MAX_SCORE - 1)
		{
			if (SCORE(i) < SCORE(i + 1))
			{
				t = SCORE(i);
				SCORE(i) = SCORE(i + 1);
				SCORE(i + 1) = t;
				name = PLAYER(i);
				PLAYER(i) = PLAYER(i + 1);
				PLAYER(i + 1) = name;
			}
		}
	}
}

static void		load_scoreboard(t_env *env, int fd)
{
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i % 2 == 0)
			env->scoreboard[i / 2].player = ft_strdup(line);
		else
			env->scoreboard[i / 2].score = ft_atoi(line);
		i++;
	}
	free(line);
	sort_score(env);
}

void			init_scoreboard(t_env *env)
{
	int			fd;

	if ((fd = open(".scoreboard", O_RDONLY)) == -1)
		return ;
	load_scoreboard(env, fd);
	close(fd);
}
