# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:36:49 by csturm            #+#    #+#              #
#    Updated: 2023/12/12 17:17:06 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I.

SRC:= core_operations.c push_swap.c parse_operations_1.c parse_operations_2.c parse_operations_3.c simple_sort.c sort_utils.c sort.c utils.c indexes.c one_arg.c
OBJ:= $(SRC:.c=.o)

NAME = libftpushswap.a
PRINTF = Printf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF) --no-print-directory
	cp Printf/libftprintf.a .
	mv libftprintf.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF) fclean --no-print-directory

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
