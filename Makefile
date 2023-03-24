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

SRC_FILES = ft_magic/push_swap.c utils/ft_arg_validation.c utils/actions.c \
			ft_magic/ft_magic.c utils/actions_utilities.c \
			ft_magic/ft_create_stack_a.c utils/ft_stack_freer.c


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

