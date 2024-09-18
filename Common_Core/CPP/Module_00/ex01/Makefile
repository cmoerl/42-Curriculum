# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 13:45:34 by csturm            #+#    #+#              #
#    Updated: 2024/09/18 13:04:16 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name and Compiler Settings
NAME := phonebook
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -g -std=c++98 -pedantic
CLEANUP := rm -rf

# Directory Paths
OBJECTS_PATH := obj/

# Source and Object Files
SOURCE_FILES := main.cpp \
				PhoneBook.cpp \
				Contact.cpp


OBJECTS := $(SOURCE_FILES:%.cpp=$(OBJECTS_PATH)%.o)

# Build the Project
all: $(NAME)

# Linking the Program
$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "linking successful - executable $(NAME) created"

# Compiling Source Files
$(OBJECTS_PATH)%.o: %.cpp
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
	@echo "cleanup completed"

# Recompile the Projects
re: fclean all
	@echo "recompilation completed"

# Phony Targets
.PHONY: all clean fclean re