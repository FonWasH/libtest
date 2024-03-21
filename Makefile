SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

SRC		= main.c \
		  globals/globals.c \
		  ft_mandatory.c \
		  ft_bonus.c \
		  ft_call_test.c \
		  utils/ft_utils.c \
		  utils/ft_print_test.c \
		  tests/ft_test_ascii.c \
		  tests/ft_test_atoi.c \
		  tests/ft_test_itoa.c \
		  tests/ft_test_strdup.c \
		  tests/ft_test_strlen.c \
		  tests/ft_test_memset.c \
		  tests/ft_test_bzero.c \
		  tests/ft_test_memcpy.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS	= ${SRCS:.c=.o}

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined

NAME	= libtest

RM		= rm -f


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${INC_DIR} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C .. -f Makefile
			${CC} ${CFLAGS} -o $@ ${OBJS} ../libft.a

$bonus:		${OBJS}
			@make bonus -C .. -f Makefile
			${CC} ${CFLAGS} -o $@ ${OBJS} ../libft.a

clean:
			@make clean -C .. -f Makefile
			${RM} ${OBJS}

fclean:		clean
			@make fclean -C .. -f Makefile
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all bonus clean fclean re
