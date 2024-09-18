# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csturm <csturm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:20:03 by csturm            #+#    #+#              #
#    Updated: 2024/09/18 13:35:44 by csturm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name and Compiler Settings
NAME := megaphone
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -g -std=c++98 -pedantic
CLEANUP := rm -rf

# Source and Object Files
SOURCE_FILES := megaphone.cpp

OBJECTS := $(SOURCE_FILES:%.cpp=%.o)

# Build the Project
all: $(NAME)

# Linking the Program
$(NAME): $(OBJECTS)
	@$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "linking successful - executable $(NAME) created"

# Compiling Source Files
%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@echo "$< compiled successfully"

# Cleaning Up Object Files
clean:
	@$(CLEANUP) $(OBJECTS)
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