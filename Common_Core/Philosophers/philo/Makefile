# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:46:54 by csturm            #+#    #+#              #
#    Updated: 2024/05/13 15:58:19 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name and Compiler Settings
NAME := philo
COMPILER := cc
FLAGS := -Wall -Wextra -Werror -g
CLEANUP := rm -rf

# Directory Paths
OBJECTS_PATH := obj/
SOURCES_PATH := src/

# Source and Object Files

SOURCE_FILES := main.c \
				error_management/error.c error_management/free_data.c \
				initialisation/init_data.c initialisation/init_forks.c initialisation/init_philos.c \
				minilib/ft_atoi_long.c minilib/ft_isdigit.c minilib/ft_strlen.c minilib/ft_strncmp.c \
				minilib/ft_iswhitespace.c minilib/ft_memcpy.c \
				time/get_time.c time/get_start_time.c \
				dinner_routine/dinner.c dinner_routine/philo_eat.c dinner_routine/philo_sleep.c \
				dinner_routine/philo_think.c dinner_routine/philo_routine.c \
				threads/create_threads.c threads/join_threads.c \
				status/print_status.c \
				# monitor/monitor_routine.c \

OBJECTS := $(SOURCE_FILES:%.c=$(OBJECTS_PATH)%.o)

# Build the Project
all: $(NAME)

# Linking the Program
$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)

# Compiling Source Files
$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(FLAGS) -c $< -o $@

# Cleaning Up Object Files
clean:
	@$(CLEANUP) $(OBJECTS)
	@$(CLEANUP) $(OBJECTS_PATH)

# Full Clean-Up
fclean: clean
	@$(CLEANUP) $(NAME)

# Recompile the Projects
re: fclean all

# Phony Targets
.PHONY: all clean fclean re