# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:00:59 by csturm            #+#    #+#              #
#    Updated: 2024/01/15 18:13:35 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:= cc
CFLAGS:= -Wall -Wextra -Werror

SRC:= ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
		ft_bzero.c ft_isascii.c ft_memcmp.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
		ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalnum.c \
		ft_isprint.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_utoa.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_ptr.c \
		ft_print_str.c ft_print_unsigned_int.c ft_printf.c ft_atoi_long.c ft_iswhitespace.c \
		ft_strncpy.c

OBJ:= $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re