/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:14:17 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:17:16 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <game.h>

void			load_ascii(t_env *env, int n)
{
	char		*str;
	int			nb;
	int			fd;

	str = ft_strdup(ASCII_PATH);
	str[ASCII_POS] = n + '0';
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		env->ascii.ascii_on = 0;
		return ;
	}
	get_next_line(fd, &str);
	env->ascii.size_h = ft_atoi(str);
	get_next_line(fd, &str);
	env->ascii.size_w = ft_atoi(str);
	nb = -1;
	while (get_next_line(fd, &str) > 0 && ++nb >= 0)
		ft_strcpy(env->ascii.nb[nb / env->ascii.size_h][nb % env->ascii.size_h],
				str);
	free(str);
}
