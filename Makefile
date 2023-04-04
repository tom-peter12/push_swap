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

SRC_FILES = ft_arg_check/ft_arg_util.c \
			ft_arg_check/ft_check_duplicate.c \
			ft_arg_check/ft_check_invalid_args.c \
			ft_arg_check/ft_check_empty.c \
			ft_operations/ft_rev_rotate.c \
			ft_operations/ft_rotate.c \
			ft_operations/ft_swap.c \
			ft_sort/ft_magic.c \
			ft_sort/push_swap.c \
			ft_utils/ft_freer.c \
			ft_utils/ft_stack_freer.c \
			ft_utils/ft_put_error.c\
			ft_utils/ft_print.c


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

