/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:10:04 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:15:21 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <sys/types.h>
#include <game.h>

int					main(int argc, char **argv)
{
	t_env				env;
	t_menu				ret_menu;

	main_init(&env, &argc, &argv);
	ret_menu = menu(&env);
	if (ret_menu == _play || ret_menu == _load)
	{
		main_loop(&env);
		save_score(&env);
	}
	endwin();
	return (0);
}
