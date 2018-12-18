# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 21:51:03 by qtran             #+#    #+#              #
#    Updated: 2018/12/18 20:17:18 by qtran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes/
SRC_DIR = ./src/
SRC_NAMES = $(addprefix src/, $(shell ls $(SRC_DIR) | grep -E ".+\.c"))
OBJ = $(SRC_NAMES:.c=.o)
NAME = ft_ls

LIB_DIR = ./libft/
LIBFT = ./libft/libft.a

BUILD_DIR = ./build/
BUILD_OBJ = $(addprefix $BUILD_DIR), $(OBJ))

#########################
#all: $(BUILD_DIR) $(LIBFT) $(NAME)
#
#$(BUILD_DIR):
#	mkdir -p $(BUILD_DIR)
#
#$(BUILD_DIR)%.o:$(SRCDIR)%.c
#	$(CC) $(CFLAGS) -I
#########################

all:
	$(CC) $(SRC_NAMES) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
