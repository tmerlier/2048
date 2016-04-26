# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 11:32:11 by rbernand          #+#    #+#              #
#    Updated: 2014/03/26 20:28:14 by rbernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCDIR=srcs/
OBJDIR=objs/
HEADER=includes/
FLAGS=-Wall -Wextra -Werror -g
SRC=ft_atoi.c \
	ft_bzero.c \
	ft_flags.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_iswhite.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstcount.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_open.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strcdup.c \
	ft_strcequ.c \
	ft_strchr.c \
	ft_strcjoin.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tabdel.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_uitoa.c \
	get_next_line.c
NBSRC=$(shell echo $(SRC) | wc -w | sed -e 's/^[ \t]*//')
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

fclean: clean	
	@rm -f $(NAME)

re: fclean all
