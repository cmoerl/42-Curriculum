# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:33:15 by csturm            #+#    #+#              #
#    Updated: 2024/01/17 17:40:19 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Werror -Wextra

SRC:= main.c utils.c
OBJ:= $(SRC:.c=.o)

NAME = pipex

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C ./Libft --no-print-directory
	$(CC) $(CFLAGS) $(OBJ) ./Libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./Libft clean --no-print-directory
	rm -f $(OBJ)	

fclean: clean
	$(MAKE) -C ./Libft fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 