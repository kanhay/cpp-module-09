# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 14:08:54 by khanhayf          #+#    #+#              #
#    Updated: 2024/03/16 15:13:35 by khanhayf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
FLAGSCPP = -Wall -Wextra -Werror -std=c++98
HEAD = PmergeMe.hpp
SRC = main.cpp PmergeMe.cpp
OBJ = main.o PmergeMe.o
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