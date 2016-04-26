# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 11:32:11 by rbernand          #+#    #+#              #
#    Updated: 2015/03/01 23:18:52 by rbernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game_2048
HEADER=includes/
FLAGS=-Wall -Wextra -Werror -g -Ofast
FLAGSMLX=-L/usr/X11/lib -lmlx -lXext -lX11
DIRSRC=srcs/
DIROBJ=objs/
DIRLIB=lib/
INCLUDES=includes/
SRCS=main.c \
	 init.c \
	 random.c \
	 signal.c \
	 winsize.c \
	 print_plate.c \
	 move_plate.c \
	 loop.c \
	 end.c \
	 ascii.c \
	 menu.c \
	save_load.c \
	usage.c \
	save_score.c \
	dump_score.c \
	load_score.c \
	load_ascii.c \
	help.c \
	save_plate.c

OBJS=$(SRCS:%.c=$(DIROBJ)%.o)
CC=/usr/local/bin/gcc

all: init $(NAME) end

init:
	@tput init
	@make -C libft
	@cp libft/libft.a $(DIRLIB)
	@make -C getopt
	@cp getopt/libopt.a $(DIRLIB)

end:
	@echo "\033[2K\t\033[1;36m$(NAME)\t\t\033[0;32m[ready]\033[0m"
	@cp $(NAME) ./bin/

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(FLAGS) $^ -L$(DIRLIB) -lopt -lft $(FLAGSMLX) -lncurses

$(DIROBJ)%.o: $(DIRSRC)%.c $(INCLUDES)
	@echo "Compiling : " $<
	@$(CC) -o $@ -c $< $(FLAGS)  -I$(INCLUDES) -I/opt/X11/include
	@tput cuu1


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
