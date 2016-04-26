/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:13:33 by tmerlier          #+#    #+#             */
/*   Updated: 2015/03/01 23:14:10 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <game.h>

void			save_plate(t_env *env)
{
	int				fd;
	int				x;
	int				y;

	if ((fd = open(".saved_game", O_WRONLY | O_CREAT, S_IRWXU)) == -1)
		exit(0);
	x = -1;
	ft_putnbr_fd(env->size, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(env->score, fd);
	ft_putchar_fd('\n', fd);
	while (++x < env->size)
	{
		y = -1;
		while (++y < env->size)
		{
			ft_putnbr_fd(env->plate[x][y], fd);
			ft_putchar_fd(',', fd);
		}
	}
	close(fd);
	mvprintw(1, 1, "Saved");
}
