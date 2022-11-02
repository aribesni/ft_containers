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

NAME_FT = 	ctn_ft

NAME_STD = 	ctn_std

SRCS = 		./srcs/main.cpp ./testers/my_tests/test_vector.cpp ./testers/my_tests/test_map.cpp ./testers/my_tests/test_stack.cpp

OBJ = 		${SRCS:.cpp=.o}

CC = 		c++

FLAGS = 	-Wall -Wextra -Werror -std=c++98 -g3

HEADER = 	./includes/

%.o	: 		%.cpp ./includes/map.hpp ./includes/iterator.hpp ./includes/stack.hpp ./includes/vector.hpp ./includes/utils.hpp ./testers/my_tests/test_utils.hpp
			${CC} ${FLAGS} -I ${HEADER} -c $< -o $@

all : 		${NAME}

${NAME} :	${OBJ}
			${CC}  ${OBJ} ${FLAGS} -o ${NAME}

${NAME_FT} :	${OBJ}
				${CC}  ${OBJ} ${FLAGS} -D NAMESPACE=ft -o ${NAME_FT}

${NAME_STD} :	${OBJ}
				${CC}  ${OBJ} ${FLAGS} -D NAMESPACE=std -o ${NAME_STD}

clean :
			rm -f ${OBJ}

fclean : 	clean
			rm -f ${NAME} ${NAME_FT} ${NAME_STD}

re : 		fclean all

.Phony : 	all clean fclean re