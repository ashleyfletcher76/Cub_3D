# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 11:42:13 by asfletch          #+#    #+#              #
#    Updated: 2024/04/28 13:57:33 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_DEFAULT = \033[0m
COLOUR_GREEN = \033[0;32m
COLOUR_MAGENTA = \033[0;35m
COLOUR_END = \033[0m

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Define directories
SRC_DIR = src/
OBJ_DIR = obj/

# Source files for the regular build
SRCS = strings/ft_substr.c strings/ft_strncmp.c strings/ft_strrchr.c \
		strings/ft_striteri.c strings/ft_strjoin.c strings/ft_strlcpy.c \
		strings/ft_strnstr.c strings/ft_strtrim.c strings/ft_strchr.c strings/ft_strlcat.c\
		strings/ft_strdup.c strings/ft_split.c strings/ft_strlen.c strings/ft_strmapi.c \
		strings/ft_char_join.c strings/ft_strcpy.c strings/ft_strcmp.c \
		mem_manip/ft_memchr.c mem_manip/ft_memcpy.c mem_manip/ft_memcmp.c \
		mem_manip/ft_memmove.c mem_manip/ft_memset.c \
		numbers/ft_atoi.c numbers/ft_isalnum.c numbers/ft_isdigit.c \
		to_write/ft_putchar_fd.c to_write/ft_putstr_fd.c to_write/ft_putendl_fd.c \
		to_write/ft_putnbr_fd.c \
		convert/ft_tolower.c convert/ft_toupper.c convert/ft_itoa.c \
		is/ft_isalpha.c is/ft_isascii.c is/ft_isprint.c \
		alloc/ft_calloc.c alloc/ft_realloc.c \
		free/ft_freearr.c \
		ft_bzero.c \
		ft_printf/ft_printf.c ft_printf/printf_special.c ft_printf/printf_utils.c \
		ft_printf/custom_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c

BONUS = linked_list/ft_lstadd_back.c linked_list/ft_lstadd_front.c linked_list/ft_lstlast.c \
		linked_list/ft_lstnew.c linked_list/ft_lstsize.c linked_list/ft_lstdelone.c \
		linked_list/ft_lstmap.c linked_list/ft_lstiter.c linked_list/ft_lstclear.c \
		linked_list/ft_lstnth.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	# echo "$(COLOUR_GREEN)Libft compiled successfully!$(COLOUR_END)"

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	# echo "$(COLOUR_GREEN)Libft with bonus compiled successfully!$(COLOUR_END)"

clean:
	$(RM) -r $(OBJ_DIR)
	# echo "$(COLOUR_MAGENTA)Libft objects removed successfully..$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	# echo "$(COLOUR_MAGENTA)Libft cleaned successfully!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re bonus
