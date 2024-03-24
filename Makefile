SRC_DIR			= ./srcs/
INC_DIR			= ./includes/

SRC				= main.c \
		  		global/globals.c \
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
		  		tests/ft_test_memcpy.c \
		  		tests/ft_test_memmove.c \
		  		tests/ft_test_memchr.c
SRC 			:= $(filter-out %ft_test_memchr.c,$(SRC))

SRCS			= $(addprefix $(SRC_DIR), $(SRC))
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined
RM				= rm -f

NAME			= libtest

G				= \e[92m
X 				= \e[0m
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRC))
COMPILED_FILES	:= 0


all:			$(NAME)

.c.o:
				@$(CC) $(CFLAGS) -c -I $(INC_DIR) $< -o $(<:.c=.o)
				$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
				@echo -n "["
				@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
					echo -n "$(G)▰$(X)"; \
				done
				@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
					echo -n "▱"; \
				done
				@echo -n "] ($(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%) "
				@echo -n "["
				@printf "%d/%d" $(COMPILED_FILES) $(TOTAL_FILES)
				@echo -n "] "
				@printf "%s" $(notdir $<)
				@printf "\e[0K\r"

title:
				@scripts/title.sh
				@printf "\n"

$(NAME):		mandatory bonus
				@clear
				@echo "Compilation completed."

mandatory:		title $(OBJS)
				@make -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ../libft.a
				@clear
				@echo "Mandatories successfully compiled."

$bonus:			title $(OBJS)
				@make bonus -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ../libft.a
				@clear
				@echo "Bonus successfully compiled."

clean:
				@make clean -sC ..
				@$(RM) $(OBJS)
				@clear
				@echo "Clean completed."

fclean:			clean
				@printf "\e[1A\e[0K\r"
				@make fclean -sC ..
				@$(RM) $(NAME)
				@clear
				@echo "Full clean completed."

re:				fclean all
				@clear
				@echo "Recompilation completed."

.PHONY: 		all title mandatory bonus clean fclean re
