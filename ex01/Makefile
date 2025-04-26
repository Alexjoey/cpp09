# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaverge <tlaverge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 11:58:06 by amylle            #+#    #+#              #
#    Updated: 2024/10/29 14:01:19 by amylle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= ./src
INC_DIR	= ./inc
OBJ_DIR	= ./obj

SRCS	= ./main.cpp ./RPN.cpp
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
CC		= c++
CFLAGS	= -Wextra -Wall -Werror -std=c++98
INCLUDE	= -I.
RM		= rm -rf

NAME	= RPN

#---------------------------Messages--------------------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

all:	$(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -Iinc -c $< -o $@ 

$(NAME):	$(OBJS)
				@echo Compiling $(NAME)
				$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)

re:			fclean all

clean:	
				@echo "$(BOLD_YELLOW)Removing all object files and directories"
				$(RM) $(OBJ_DIR)

fclean:
				@echo "$(BOLD_YELLOW)Removing binaries"
				$(RM) $(NAME) $(OBJ_DIR)

re:			fclean all
