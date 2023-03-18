# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:48:26 by tpetros           #+#    #+#              #
#    Updated: 2023/03/10 14:48:28 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = push_swap.c ft_arg_validation.c ft_create_stack_a.c actions.c \
			ft_magic.c actions_utilities.c


CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

SRC_OBJS = ${SRC_FILES:.c=.o}

${NAME}: ${SRC_OBJS}
	cd ./libft/ && make
	${CC} ${CFLAGS} ${SRC_OBJS} ./libft/libft.a -o ${NAME}

all: ${NAME} 

clean:
	cd ./libft/ && make clean
	${RM} ${SRC_OBJS}

fclean: clean
	cd ./libft/ && make fclean
	${RM} ${NAME}

re:	fclean all

