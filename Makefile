# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 07:56:38 by asfletch          #+#    #+#              #
#    Updated: 2024/04/17 12:54:19 by asfletch         ###   ########.fr        #
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
SRCS = cube.c init/init.c hooks/hooks.c parsing/map_parsing.c \
	utils/check_arg.c utils/print_msg.c utils/map_validity.c
OBJ_DIR = obj
SRC_DIR = src/
INCLUDES = -I$(MLX42_DIR)/include -I header -I libft
LDINCLUDES = -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft -lglfw -framework Cocoa -framework OpenGL -framework IOKit
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(SRC_DIR)/, $(SRCS)) ./includes/cube3d.h ./includes/structs.h

NAME = Cube3D

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

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(DEPS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	rm -rf $(MLX42_DIR)
	@echo "$(COLOUR_MAGENTA)$(NAME) objects removed successfully..$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)
	echo "$(COLOUR_MAGENTA)$(NAME) cleaned successfully..$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
