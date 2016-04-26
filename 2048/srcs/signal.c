/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 09:15:42 by rbernand          #+#    #+#             */
/*   Updated: 2015/02/28 10:54:57 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <libft.h>

void			handle_sigint(int n)
{
	endwin();
	ft_putendl("Treats me with respect! Bad loser ...");
	ft_putendl("It is so hard to press Escape key?");
	exit(n);
}
