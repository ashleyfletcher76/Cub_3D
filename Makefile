# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 07:56:38 by asfletch          #+#    #+#              #
#    Updated: 2024/05/10 18:46:53 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_DEFAULT = \033[0m
COLOUR_GREEN = \033[0;32m
COLOUR_BLUE = \033[0;34m
COLOUR_MAGENTA = \033[0;35m
COLOUR_END = \033[0m

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I./includes/ -g
SRCS = cube.c init/init.c init/init_player.c init/init_2d_map.c \
	hooks/hooks.c hooks/keys.c hooks/keys2.c hooks/close_minimap.c \
	parsing/map_parsing.c parsing/map_validity.c parsing/convert_utils.c \
	parsing/check_arg.c parsing/check_map_details.c parsing/check_utils.c \
	parsing/check_start.c parsing/remove_space.c parsing/check_arg_utils.c \
	parsing/flood_fill.c parsing/convert_compare.c \
	parsing/map_details.c parsing/get_details.c \
	drawing/draw_player.c drawing/reset_player.c drawing/rays.c drawing/two_d_map.c \
	drawing/three_d_map.c drawing/rays_helper.c\
	gameplay/prevent_collision.c \
	textures/textures.c \
	utils/print_msg.c utils/free_functions.c utils/print_map.c \
	utils/check_chars.c utils/utils.c /utils/maths.c utils/utils2.c

SRCS_BON = cube_bonus.c init/init.c init/init_player.c init/init_2d_map.c \
	init/init_instructions.c \
	hooks/hooks.c hooks/keys.c hooks/keys2.c hooks/hook_functions.c \
	parsing/map_parsing.c parsing/map_validity.c parsing/convert_utils.c \
	parsing/check_arg.c parsing/check_map_details.c  parsing/check_utils.c \
	parsing/check_start.c parsing/remove_space.c parsing/check_arg_utils.c \
	parsing/flood_fill.c parsing/convert_compare.c \
	parsing/map_details.c parsing/get_details.c \
	drawing/draw_player.c drawing/reset_player.c drawing/rays.c drawing/two_d_map.c \
	drawing/three_d_map.c drawing/rays_helper.c drawing/draw_door.c\
	gameplay/prevent_collision.c gameplay/instructions.c \
	textures/textures.c \
	utils/print_msg.c utils/free_functions.c utils/print_map.c \
	utils/check_chars.c utils/utils.c /utils/maths.c utils/utils2.c

OBJ_DIR = obj
OBJ_DIR_BON = obj_bon
SRC_DIR = src/
SRC_DIR_BON = src_bonus/
INCLUDES = -I$(MLX42_DIR)/include -I header -I libft
INCLUDES += -Iincludes_bon
LDINCLUDES = -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft -lglfw -framework Cocoa -framework OpenGL -framework IOKit
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_BON = $(addprefix $(OBJ_DIR_BON)/, $(SRCS_BON:.c=.o))
DEPS = $(addprefix $(SRC_DIR)/, $(SRCS)) ./includes/cub3d.h ./includes/structs.h
BONUS_DEPS = $(addprefix $(SRC_DIR_BON)/, $(SRCS_BON)) ./includes_bon/cub3d_bonus.h ./includes_bon/structs_bonus.h

NAME = cub3D

BONUS = Bonus

all: $(NAME)

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
MLX42_DIR	= MLX42
MLX42_LIB	= $(MLX42_DIR)/build/libmlx42.a

$(LIBFT_LIB):
			make -C $(LIBFT_DIR)
			make -C $(LIBFT_DIR) bonus
$(MLX42_DIR) :
			git clone $(MLX42_URL) $(MLX42_DIR)

$(MLX42_LIB): $(MLX42_DIR)
			cd $(MLX42_DIR) && cmake -B build && cmake --build build

$(NAME): $(LIBFT_LIB) $(MLX42_LIB) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LDINCLUDES) -o $(NAME)
	echo "$(COLOUR_GREEN)$(NAME) compiled successfully!$(COLOUR_END)"

$(BONUS): $(LIBFT_LIB) $(MLX42_LIB) $(OBJ_BON)
		$(CC) $(CFLAGS) $(OBJ_BON) $(LDINCLUDES) -o $(BONUS)
	echo "$(COLOUR_GREEN)$(BONUS) compiled successfully!$(COLOUR_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(DEPS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BON)/%.o: $(SRC_DIR_BON)%.c $(BONUS_DEPS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT_LIB) $(MLX42_LIB) $(OBJ_BON)
		$(CC) $(CFLAGS) $(OBJ_BON) $(LDINCLUDES) -o $(BONUS)
	echo "$(COLOUR_GREEN)$(BONUS) compiled successfully!$(COLOUR_END)"

clean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(OBJ_DIR_BON)
	make -C $(LIBFT_DIR) clean
	rm -rf $(MLX42_DIR)
	@echo "$(COLOUR_MAGENTA)$(NAME) objects removed successfully..$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)
	echo "$(COLOUR_MAGENTA)$(NAME) cleaned successfully..$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
