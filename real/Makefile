# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 11:48:27 by badriano          #+#    #+#              #
#    Updated: 2024/08/16 08:48:55 by belmiro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Werror -Wextra
CC = cc
UTILS_DIR = ./utils
CORE_DIR = ./core
ERRORS_DIR = ./errors
MINILBX_DIR = ./minilibx_linux
MINILIB_LIB = libmlx.a
#MAIN = main.c
COMMON_SRC = $(wildcard ./*c $(ERRORS_DIR)/*.c $(CORE_DIR)/*.c $(UTILS_DIR)/*.c) # Expands to all .c files in directories
OBJ = $(COMMON_SRC:.c=.o) #$(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MINILBX_DIR) -lmlx -lX11 -lXext -o $(NAME)
	@echo "Program is ready!!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files have been cleaned successfully"

fclean: clean
	@rm -f $(NAME)
	@echo "Objects and executables removed"

re: fclean all
