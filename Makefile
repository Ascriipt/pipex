# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 00:12:03 by maparigi          #+#    #+#              #
#    Updated: 2022/05/24 16:31:44 by maparigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang

SRCS =	main.c			\
		ft_split.c		\
		utilities.c		\
		utilities2.c	\

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFlAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

aclean: all clean

re: fclean all

.PHONY: all clean fclean re bonus aclean