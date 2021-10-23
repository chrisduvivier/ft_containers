# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 15:46:24 by cduvivie          #+#    #+#              #
#    Updated: 2021/10/23 23:38:48 by nathan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of your executable
NAME		:=	test

# Compiler and compiling flags

CC			:=	clang++
FLAGS	 	:=	-Wall -Wextra -Werror -std=c++98

# Debug, use with`make DEBUG=1`

ifeq ($(DEBUG),1)
FLAGS	+= -g3 -fsanitize=address
endif

# Folder name
SRCDIR	= srcs/
INCDIR	= includes/
OBJDIR	= bin/

# Add include folder
CFLAGS	+= -I $(INCDIR)

SRCS =\
	./srcs/main.cpp\
	./srcs/vector.cpp\
	./srcs/stack.cpp\

HEADERS =\
	./includes/iterator/iterator.hpp\
	./includes/iterator/random_access_iterator.hpp\
	./includes/iterator/reverse_iterator.hpp\
	./includes/tests/tests.hpp\
	./includes/utils/utils.hpp\
	./includes/vector/vector.hpp\
	./includes/stack/stack.hpp\

VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

RM 			:=	/bin/rm -rf

SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.cpp=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(OBJDIR)%.o : %.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(SRCS) $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@ $(RM) $(OBJDIR)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re