SRC_DIR	= ./srcs/
INC_DIR	= ./includes/

SRC		= main.c \
		  globals.c \
		  ft_all_mandatory.c \
		  ft_all_bonus.c \
		  ft_check_argument.c \
		  ft_utils.c \
		  ft_print_test.c \
		  ft_test_ascii.c \
		  ft_test_atoi.c \
		  ft_test_itoa.c \
		  ft_test_strdup.c \
		  ft_test_strlen.c

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
