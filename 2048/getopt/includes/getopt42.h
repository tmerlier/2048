/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 12:15:29 by rbernand          #+#    #+#             */
/*   Updated: 2015/01/04 16:26:29 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT42_H
# define GETOPT42_H

typedef struct s_opt42			t_opt42;
typedef struct s_argv42			t_argv42;

struct							s_opt42
{
	char						s_name;
	char						*l_name;
	char						has_param;
	char						*param;
	t_opt42						*next;
};

struct							s_argv42
{
	char						*str;
	char						is_param;
	char						is_opt;
	t_argv42					*next;
};

t_opt42							*g_opt42;
t_argv42						*g_argv42;

void							set_opt42(char s, char *l, char h, void *par);
void							parse_opt42(int argc, char **argv);
void							shift_arg(int *argc, char ***argv);

void							init_argv(int argc, char **argv);
char							store_l_param(t_opt42 *opt, t_argv42 *arg);
char							store_s_param(t_opt42 *opt, t_argv42 *arg);

#endif
