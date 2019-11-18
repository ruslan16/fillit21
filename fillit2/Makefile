# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:32:13 by etristan          #+#    #+#              #
#    Updated: 2019/10/13 19:23:36 by etristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(HFILES)

CFILES = $(wildcard *.c)

HFILES = ./

NAME = fillit

OFILES = $(CFILES:.c=.o)

all: lft $(CFILES) $(NAME)

$(NAME): $(OFILES)
	$(CC) -o $@ $^ -L libft -lft

lft: libft
	$(MAKE) -C $^

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean lft all

.PHONY: all, lft, clean, fclean, re
