/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:46:54 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/30 09:58:01 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

int				gnl_copy(char **line, char *str, int ret)
{
	int		len;

	if (*line != NULL)
		ft_strdel(line);
	if (ft_strchr(str, '\n'))
	{
		*line = ft_strcdup(str, '\n');
		len = ft_strlen(*line);
		ft_memmove(str, str + len + 1, ft_strlen(str) - len);
	}
	else if (ret == 0)
	{
		*line = ft_strdup(str);
		if (str)
			ft_strdel(&str);
		return (1);
	}
	if (str == NULL && ret <= 0)
		return (0);
	return (1);
}

int				gnl_read(int fd, char **str)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	while (!ft_strchr(*str, '\n') && (ret = read(fd, buf, BUFF_SIZE)) >= 1)
	{
		buf[ret] = 0;
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char			*str;
	int					ret;

	if (str == NULL)
		str = ft_strnew(0);
	ret = gnl_read(fd, &str);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && *str == 0)
		return (0);
	else
		return (gnl_copy(line, str, ret));
}
