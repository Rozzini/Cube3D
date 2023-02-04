# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:25:24 by gabdoush          #+#    #+#              #
#    Updated: 2023/01/02 06:33:40 by gabdoush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = cub3d

FILES = ./cub3d.c\
		./init_game.c\
		./start_game.c\
		./close_game.c\
		\
		./utils/color_utils.c\
		./utils/drawing_utils.c\
		\
		./movement/keys.c\
		./movement/movement_coordinates.c\
		./movement/mouse_handling.c\
		\
		./texture/gun.c\
		./texture/minimap_border.c\
		\
		./wall_collusion/wall_collusion.c\
		./wall_collusion/wall_checkers.c\
		\
		./ray_casting/rays_casting_2D.c\
		./ray_casting/rays_casting_3D.c\
		\
		./minimap/draw_minimap.c\
		\
		./action_list/list_commands.c\
		./action_list/ft_action.c\
		./parser/read_file.c\
		./parser/errors_handling.c\
		./parser/map_content/ft_get_map_content.c\
		./parser/map_content/ft_get_map_content_utils.c \
		./parser/map_content/ft_check_direction_value.c \
		./parser/map_content/ft_utils.c \
		./parser/real_map/get_real_map.c \
		./parser/real_map/ft_get_real_map.c \
		./parser/real_map/check_map_wall.c \
		./parser/real_map/check_zero_round.c \
		\
		./helper/get_next_line/get_next_line.c\
		./helper/get_next_line/get_next_line_utils.c\
#------------------------------------------------------------------------------

HEADERS = ./cub3d.h\
		  ./helper/libft/libft.h\
		  ./helper/get_next_line/get_next_line.h\

ARCS = ./helper/libft/libft.a

OBJ = $(FILES:.c=.o)

#------------------------------------------------------------------------------
OPENGL_PATH = ./helper/mlx/

MLX = $(OPENGL_PATH)libmlx.a -framework OpenGL

APPKIT = -framework AppKit

#------------------------------------------------------------------------------
MLX_FLAGS = $(MLX) $(APPKIT)

FLAGS = -g -Wall -Wextra -Werror

sanitize = -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

CC = gcc

#------------------------------------------------------------------------------
R = \033[1;31m
G = \033[1;32m
Y = \033[1;33m
B = \033[1;34m
RESET = \033[0m

#------------------------------------------------------------------------------
all: $(NAME) clean
$(NAME): $(OBJ)
	@echo "$(G)【OK】$(B)Compiling with the flags....$(RESET)"
	@echo "$(B)Compiling MiniLibx....$(RESET)"
	@make -C ./helper/mlx
	@make -C ./helper/libft
	@echo "\033c"
	@$(CC) $(FILES) $(FLAGS) $(MLX_FLAGS) -Ofast -O3 $(ARCS) -o cub3d
#	@$(CC) $(FILES) $(FLAGS) $(sanitize) $(MLX_FLAGS) $(ARCS) -o cub3d

	@echo "$(Y)—————————————————————————————————————————————————$(RESET)"

clean:
	@rm -rf $(OBJ)
	@rm -rf ./helper/get_next_line/get_next_line.o
	@rm -rf ./helper/get_next_line/get_next_line_utils.o
	@make -C ./helper/libft clean

	@echo "$(G)【OK】 $(R)❮cub3d❯ objects have been DELETED$(RESET)"
	@echo "$(Y)—————————————————————————————————————————————————$(RESET)"

fclean: clean
	@make -C ./helper/mlx clean
	@make -C ./helper/libft fclean
	@rm -rf cub3d

	@echo "$(G)【OK】 $(R)❮cub3d❯ executable have been DELETED$(RESET)"
	@echo "$(Y)—————————————————————————————————————————————————$(RESET)"

re: fclean all

.PHONY: all clean fclean re