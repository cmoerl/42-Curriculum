# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:33:15 by csturm            #+#    #+#              #
#    Updated: 2024/01/27 18:05:55 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror

SRC:= main.c utils.c error_free_paths.c parent.c child.c
LIBFT_DIR:= ./Libft
LIBFT:= $(LIBFT_DIR)/libft.a

OBJ:= $(SRC:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	rm -f $(OBJ)	

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 