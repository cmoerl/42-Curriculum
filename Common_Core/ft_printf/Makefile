# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 17:00:04 by csturm            #+#    #+#              #
#    Updated: 2023/10/03 16:54:04 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Werror -Wextra -I.

SRC:= ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsigned_int.c
OBJ:= $(SRC:.c=.o)

NAME = libftprintf.a
LIBFT = Libft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT) --no-print-directory
	cp Libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) fclean --no-print-directory

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
