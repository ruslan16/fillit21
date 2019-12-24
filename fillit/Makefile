# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:32:13 by etristan          #+#    #+#              #
#    Updated: 2019/12/14 16:49:43 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(HFILES)

CFILES = algo_field.c \
         algo_collision.c \
         algo_shift.c \
         algo_tetra.c \
         list_create.c \
         init_figure.c \
         check_valid.c \
         main.c

HFILES = ./

NAME = fillit

OFILES = $(CFILES:.c=.o)

all: lft $(CFILES) $(NAME)

$(NAME): lft $(OFILES)
	$(CC) -o $@ $(OFILES) -L libft -lft

lft: libft
	@$(MAKE) -C $^

clean:
	/bin/rm -rf $(OFILES)
	$(MAKE) clean -C libft

fclean: clean
	/bin/rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean lft all

.PHONY: all, lft, clean, fclean, re
