/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:06:07 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 21:26:04 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <game.h>

void				pop_new(int **plate, int size)
{
	int				x;
	int				y;

	while (42)
	{
		x = rand() % (size);
		y = rand() % (size);
		if (plate[x][y] == 0)
		{
			plate[x][y] = (rand() % OCCUR_4) == 0 ? 4 : 2;
			return ;
		}
	}
}
