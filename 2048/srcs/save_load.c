/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:21:00 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:13:41 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <game.h>

static void		save_numbers(int **plate, char **numbers, int size)
{
	int			i;

	i = -1;
	while (numbers[++i])
	{
		plate[i / size][i % size] = ft_atoi(numbers[i]);
		free(numbers[i]);
	}
}

void			load_game(t_env *env)
{
	int				fd;
	char			*line;
	char			**numbers;

	if ((fd = open(".saved_game", O_RDONLY)) == -1)
	{
		env->load = 0;
		return ;
	}
	line = NULL;
	get_next_line(fd, &line);
	env->size = ft_atoi(line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	env->score = ft_atoi(line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	close(fd);
	numbers = ft_strsplit(line, ',');
	free(line);
	save_numbers(env->plate, numbers, env->size);
	free(numbers);
}
