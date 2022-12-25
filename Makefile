# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraspors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 00:06:52 by mraspors          #+#    #+#              #
#    Updated: 2022/12/25 05:37:43 by mraspors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cube3D

CFLAG = -Wall -Werror -Wextra

CC = gcc

mlx = ./mlx/libmlx.a

FILES = cube.c ./src/parsing/parsing.c ./src/parsing/read_map.c ./src/utils/utils.c\
		./src/parsing/save_map_config.c ./src/parsing/check_map_config.c
		
OBJECTS = $(FILES:.c=.o)

HEADER = cube.h

LIBFT = cd libft && make

LIB = libft/libft.a

all : $(NAME)

.c.o: $(HEADER)
		$(CC) $(CFLAG) -c $< -o $(<:.c=.o) 
		
$(NAME)	:  $(OBJECTS)
		$(LIBFT)
		make -C ./mlx
		$(CC) $(CFLAGS) -o $(NAME) $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit

bonus :
		$(LIBFT)
		make -C ./mlx
		$(CC) $(CFLAGS) -o so_long_bonus $(FILES_BONUS) $(LIB) $(mlx) -framework OpenGL -framework AppKit


clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		rm -f so_long_bonus
		make clean -C mlx

re : fclean all

reb : fclean bonus