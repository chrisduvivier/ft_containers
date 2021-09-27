# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 15:46:24 by cduvivie          #+#    #+#              #
#    Updated: 2021/09/27 11:59:24 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	a.out
CC			:=	clang++
FLAGS	 	:=	-Wall -Wextra -Werror
RM 			:=	/bin/rm -rf
OBJDIR		:= ./obj/

SRCS		:=	main.cpp
				

OBJ			:= $(SRCS:.cpp=.o)
OBJS 		:= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(SRCS)
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o:%.cpp $(SRCS)
	@ $(CC) $(FLAGS) -c -o $@ $<

$(OBJDIR):
	@ mkdir -p $(OBJDIR)

clean:
	@ $(RM) $(OBJDIR)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re