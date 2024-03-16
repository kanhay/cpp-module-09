# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 12:31:33 by khanhayf          #+#    #+#              #
#    Updated: 2024/03/12 13:43:08 by khanhayf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CC = c++
FLAGSCPP = -Wall -Wextra -Werror -std=c++98
HEAD = RPN.hpp
SRC = main.cpp RPN.cpp
OBJ = main.o RPN.o
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGSCPP) $(OBJ) -o $@
	
%.o : %.cpp $(HEAD)
	$(CC) $(FLAGSCPP) -c $<

clean :
	$(RM) $(OBJ)

fclean :clean
	$(RM) $(NAME)
	
re : fclean all