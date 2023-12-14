# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:36:49 by csturm            #+#    #+#              #
#    Updated: 2023/12/14 16:30:27 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I.

SRC:= core_operations.c main.c parse_operations_1.c parse_operations_2.c parse_operations_3.c simple_sort.c sort_utils.c sort.c utils.c indexes.c one_arg.c
OBJ:= $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C ./Libft --no-print-directory
	$(CC) $(CFLAGS) $(OBJ) ./Libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C ./Libft fclean --no-print-directory
	rm -f $(OBJ)	

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all

.PHONY: all clean fclean re 
