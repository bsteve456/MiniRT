# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blacking <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 10:03:56 by blacking          #+#    #+#              #
#    Updated: 2020/01/25 18:27:55 by blacking         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Werror -Wextra
INC=-Iincludes
NAME=minirt
FILE=minirt.c \
	  srcs/display_loop.c \
	  srcs/vector_calcul.c \
	  srcs/matrix_calcul.c \
	  srcs/parse_info.c \
	  srcs/fill_scene_lst.c \
	  srcs/fill_object_lst.c \
	  srcs/minirt_utils.c \
	  srcs/init_data_ray.c \
	  srcs/add_pixel_color.c \
	  srcs/sphere_plane_inter.c \
	  srcs/light.c \
	  srcs/shadow.c \
	  srcs/shadow_plane_sphere.c \
	  srcs/square_inter.c \
	  srcs/inter_cylinder.c \
	  srcs/inter_disk.c \
	  srcs/inter_triangle.c \
	  srcs/shadow_square.c \
	  srcs/shadow_cylinder.c \
	  srcs/shadow_triangle.c \
	  srcs/minirt_utils2.c \
	  srcs/lst_functions.c \
	  srcs/screenshot.c

OBJ=$(FILE:.c=.o)

all :$(NAME)

$(NAME): $(OBJ) ./includes/minirt.h
	$(CC) $(CFLAGS) $(INC) $(OBJ) libft/libft.a -L./libft -L./minilibx_linux -lmlx -lXext -lX11 -lm -o $(NAME)
.c.o: $(FILE)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -rf *.o ./srcs/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
