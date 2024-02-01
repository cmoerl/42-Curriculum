# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:33:15 by csturm            #+#    #+#              #
#    Updated: 2024/02/01 13:03:36 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror 
LIBS:= -L./minilibx-linux -lXext -lX11 -lm -lz -lmlx

FILES:= main init render image events

SRC_DIR= ./src
SRC:= $(FILES:%=$(SRC_DIR)/%.c)

LIBFT_DIR:= ./Libft
LIBFT:= $(LIBFT_DIR)/libft.a

OBJ_DIR:= ./obj
OBJ:= $(FILES:%=$(OBJ_DIR)/%.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)	

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 