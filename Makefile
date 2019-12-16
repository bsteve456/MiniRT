# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blacking <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 10:03:56 by blacking          #+#    #+#              #
#    Updated: 2019/12/16 11:25:02 by blacking         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
INC=-Iincludes
NAME=minirt
FILE=minirt.c \
	  srcs/display_loop_rt.c
OBJ=$(FILE:.c=.o)

all :$(NAME)

$(NAME): $(OBJ) ./includes/minirt.h
	$(CC) $(CFLAGS) $(INC) $(OBJ) -L./minilibx_linux -lmlx -lXext -lX11 -lm -o $(NAME)
.c.o: $(FILE)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -rf *.o ./srcs/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all