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
NAME_BONUS = checker

SRC_COMM =  src/ft_arg_check/ft_arg_util.c \
			src/ft_arg_check/ft_check_duplicate.c \
			src/ft_arg_check/ft_check_invalid_args.c \
			src/ft_arg_check/ft_check_empty.c \
			src/ft_operations/ft_rev_rotate.c \
			src/ft_operations/ft_rotate.c \
			src/ft_operations/ft_swap.c \
			src/ft_operations/ft_push.c \
			src/ft_sort/push_swap.c \
			src/ft_sort/ft_3_elem.c \
			src/ft_sort/ft_sort_utils.c \
			src/ft_sort/ft_tiny_sort.c \
			src/ft_sort/ft_big_sort.c \
			src/ft_sort/ft_sort_big_utils.c \
			src/ft_utils/ft_freer.c \
			src/ft_utils/ft_stack_freer.c \
			src/ft_utils/ft_put_error.c \
			src/ft_utils/ft_print.c \
			src/ft_utils/ft_array_utils.c \
			src/ft_utils/ft_abs.c \

SRC_FILES = src/ft_sort/main.c

SRC_BONUS = bonus/ft_checker.c \
			bonus/get_next_line/get_next_line.c \
			bonus/get_next_line/get_next_line_utils.c \

CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

SRC_OBJS = ${SRC_FILES:.c=.o}
COMM_OBJS = ${SRC_COMM:.c=.o}
BONUS_OBJS = ${SRC_BONUS:.c=.o}

${NAME}: ${SRC_OBJS} ${COMM_OBJS}
	cd ./includes/libft/ && make
	${CC} ${CFLAGS} ${SRC_OBJS} ${COMM_OBJS} ./includes/libft/libft.a -o ${NAME}

all: ${NAME} 

bonus: ${COMM_OBJS} ${BONUS_OBJS}
	cd ./includes/libft/ && make
	${CC} ${CFLAGS} ${COMM_OBJS} ${BONUS_OBJS} ./includes/libft/libft.a -o ${NAME_BONUS}

clean:
	cd ./includes/libft/ && make clean
	${RM} ${SRC_OBJS} ${COMM_OBJS} ${BONUS_OBJS}

fclean: clean
	cd ./includes/libft/ && make fclean
	${RM} ${NAME} ${NAME_BONUS}

re:	fclean all
