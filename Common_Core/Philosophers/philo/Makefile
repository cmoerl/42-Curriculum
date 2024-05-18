# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 19:46:54 by csturm            #+#    #+#              #
#    Updated: 2024/05/18 14:37:08 by csturm           ###   ########.fr        #
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
				initialisation/init_data.c initialisation/init_forks.c initialisation/init_philos.c \
				initialisation/free_data.c \
				minilib/ft_atoi_long.c minilib/ft_isdigit.c minilib/ft_strlen.c minilib/ft_strncmp.c \
				minilib/ft_iswhitespace.c minilib/ft_memcpy.c \
				monitor/monitor_routine.c monitor/create_monitor.c \
				philos/philo_eat.c philos/philo_routine.c philos/philo_sleep.c philos/philo_think.c \
				printing/error.c printing/print_status.c \
				threads/create_threads.c threads/join_threads.c \
				time/get_time.c time/get_start_time.c \

OBJECTS := $(SOURCE_FILES:%.c=$(OBJECTS_PATH)%.o)

# Build the Project
all: $(NAME)

# Linking the Program
$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "linking successfull - executable $(NAME) created"

# Compiling Source Files
$(OBJECTS_PATH)%.o: $(SOURCES_PATH)%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@echo "$< compiled successfully"

# Cleaning Up Object Files
clean:
	@$(CLEANUP) $(OBJECTS)
	@$(CLEANUP) $(OBJECTS_PATH)
	@echo "object cleanup completed"

# Full Clean-Up
fclean: clean
	@$(CLEANUP) $(NAME)
	@echo "$(NAME) cleanup completed"

# Recompile the Projects
re: fclean all
	@echo "recompilation completed"

# Phony Targets
.PHONY: all clean fclean re