# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:33:15 by csturm            #+#    #+#              #
#    Updated: 2024/01/22 15:21:27 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror

SRC:= 
LIBFT:= ${wildcard ./Libft/*.c}

OBJ:= $(SRC:.c=.o)
LIBFT_OBJ:= $(LIBFT:.c=.o)

NAME = fractol

all: $(NAME)
	cc -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm -o fractol fractol.c
$(NAME): $(OBJ) $(LIBFT_OBJ)
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