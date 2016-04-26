# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 11:32:11 by rbernand          #+#    #+#              #
#    Updated: 2015/01/04 16:23:45 by rbernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libopt.a
SRCDIR=srcs/
OBJDIR=objs/
HEADER=includes/
FLAGS=-Wall -Wextra -Werror -g
SRC=getopt.c \
	store_param.c \
	argv42.c \
	opt42.c
OBJO=$(SRC:%.c=$(OBJDIR)%.o)

all: init $(NAME) end

init:
	@tput init
end:
	@echo "\033[2K\t\033[1;36m$(NAME)\t\t\033[0;32m[ready]\033[0m"

$(NAME): $(OBJO)
	@ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\033[2KCompiling $< :"
	@gcc $(FLAGS) -o $@ -c $< -I$(HEADER)
	@ar -c -q $(NAME) $@
	@tput cuu1
	
clean:
	@rm -f $(OBJO)

exec: fclean $(NAME)
	gcc -L. -lopt srcs/main.c -Iincludes -Llibft -lft

fclean: clean	
	@rm -f $(NAME)

re: fclean all
