/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:20:09 by rbernand          #+#    #+#             */
/*   Updated: 2015/03/01 23:34:12 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define OCCUR_4			8
# define DEFAULT_SIZE		4
# define MIN_W				30
# define MIN_H				5
# define ON					1
# define OFF				0
# define DEFAULT_WIN_VALUE	2048
# define MAX_SCORE			3

# define MAX_ASCII			3
# define ASCII_PATH			"./misc/ascii_numberX"
# define ASCII_POS			19
# define INTRO_W			27
# define INTRO_H			5
# define PLATE(X,Y)			env->plate[X][Y]
# define SCORE(X)			env->scoreboard[X].score
# define PLAYER(X)			env->scoreboard[X].player

typedef struct s_env		t_env;
typedef struct s_ascii		t_ascii;
typedef struct s_score		t_score;
typedef struct winsize		t_winsize;
typedef enum e_color		t_color;
typedef enum e_menu			t_menu;
typedef int					(*t_main_fct)(t_env *);

enum						e_color
{
	_WHITE = 100,
	_n2,
	_n4,
	_n8,
	_n16,
	_n32,
	_n64,
	_n128,
	_n256,
	_n512,
	_n1024,
	_n2048,
	_n4096
};

enum						e_menu
{
	_invalid = -1,
	_play,
	_load,
	_score,
	_help,
	_leave
};

enum		e_const
{
	WIN_VALUE = 512
};

struct						s_score
{
	char			*player;
	int				score;
};

struct						s_ascii
{
	char				nb[10][10][11];
	int					size_h;
	int					size_w;
	int					ascii_on;
};

struct						s_env
{
	int					h;
	int					w;
	int					score;
	int					size;
	int					**plate;
	int					**last_plate;
	char				*tsize;
	int					cell_w;
	int					load;
	int					undo;
	t_ascii				ascii;
	t_score				scoreboard[MAX_SCORE];
	int					cell_h;
	int					has_move;
	int					win;
};

void						main_init(t_env *env, int *argc, char ***argv);
void						init_scoreboard(t_env *env);
void						pop_new(int **plate, int size);
void						set_winsize(t_env *env);
void						print_plate(t_env *env);
int							move_plate(t_env *env, int key);
int							main_loop(t_env *env);
void						handle_sigint(int n);
int							check_end(t_env *env);
void						load_ascii(t_env *env, int n);
void						put_ascii_middle(t_env *e, int value, int x, int y);
t_menu						menu(t_env *env);
void						save_plate(t_env *env);
void						load_game(t_env *env);
void						print_usage(char *str);
void						print_help(void);
void						init_scoreboard(t_env *env);
void						save_score(t_env *env);
void						dump_score(t_env *env);

#endif
