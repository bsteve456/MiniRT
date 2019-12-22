# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blacking <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 20:03:43 by blacking          #+#    #+#              #
#    Updated: 2019/12/22 16:02:33 by blacking         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra

NAME=libft.a
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) libft.h
	 ar rc $(NAME) $(OBJ)
.c.o: $(SRC)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
