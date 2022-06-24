# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:44:46 by aribesni          #+#    #+#              #
#    Updated: 2022/06/14 16:44:47 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		container

SRC = 		main.cpp

SRCS = 		${addprefix ./srcs/, ${SRC}}

OBJ = 		${SRCS:.cpp=.o}

CC = 		c++

FLAGS = 	-Wall -Wextra -Werror -std=c++98

HEADER = 	./includes/

%.o	: 		%.cpp ./includes/vector.hpp ./includes/iterator.hpp
			${CC} ${FLAGS} -I ${HEADER} -c $< -o $@

all : 		${NAME}

${NAME} :	${OBJ}
			${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean :
			rm -f ${OBJ}

fclean : 	clean
			rm -f ${NAME}

re : 		fclean all

.Phony : 	all clean fclean re