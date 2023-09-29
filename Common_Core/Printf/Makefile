# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 17:00:04 by csturm            #+#    #+#              #
#    Updated: 2023/09/29 12:24:40 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I.

SRC:= ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_ptr.c ft_print_str.c
OBJ:= $(SRC:.c=.o)

NAME = libftprintf.a
LIBFT = Libft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp Libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
