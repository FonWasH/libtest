SRC_DIR			= ./srcs/
INC_DIR			= ./includes/

SRC				= main.c \
		  		global/globals.c \
		  		ft_call_test.c \
		  		utils/ft_utils.c \
		  		utils/ft_print_test.c \
		  		tests/ft_test_ascii.c \
				tests/ft_test_strlen.c \
				tests/ft_test_memset.c \
				tests/ft_test_bzero.c \
		  		tests/ft_test_memcpy.c \
		  		tests/ft_test_memmove.c \
				tests/ft_test_strlcpy.c \
				tests/ft_test_strlcat.c \
				tests/ft_test_strchr.c \
				tests/ft_test_strrchr.c \
				tests/ft_test_strncmp.c \
		  		tests/ft_test_memchr.c \
				tests/ft_test_memcmp.c \
				tests/ft_test_strnstr.c \
		  		tests/ft_test_atoi.c \
				tests/ft_test_calloc.c \
		  		tests/ft_test_strdup.c \
				tests/ft_test_substr.c \
				tests/ft_test_strjoin.c \
				tests/ft_test_strtrim.c \
				tests/ft_test_split.c \
		  		tests/ft_test_itoa.c \
				tests/ft_test_strmapi.c \
				tests/ft_test_striteri.c \
				tests/ft_test_putchar_fd.c \
				tests/ft_test_putstr_fd.c \
				tests/ft_test_putendl_fd.c \
				tests/ft_test_putnbr_fd.c \

SRC_BONUS		= global/globals_bonus.c \
				tests/ft_test_lstnew.c \
				tests/ft_test_lstadd_front.c \
				tests/ft_test_lstsize.c \
				tests/ft_test_lstlast.c \
				tests/ft_test_lstadd_back.c \
				tests/ft_test_lstdelone.c \
				tests/ft_test_lstclear.c \
				tests/ft_test_lstiter.c \
				tests/ft_test_lstmap.c
SRC_BONUS 		:= $(filter-out %globals_bonus.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstnew.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstadd_front.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstsize.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstlast.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstadd_back.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstdelone.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstclear.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstiter.c,$(SRC_BONUS))
SRC_BONUS 		:= $(filter-out %ft_test_lstmap.c,$(SRC_BONUS))

SRCS			= $(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS		= ${addprefix ${SRC_DIR}, ${SRC_BONUS}}

OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

LINKER_FLAGS 	= -lbsd

CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined #-lbsd
RM				= rm -f

NAME			= libtest

G				= \e[92m
X 				= \e[0m
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRC))
COMPILED_FILES	:= 0

CHECK_SCRIPT	= ./scripts/check_files.sh
CHECK_BONUS		= ./scripts/check_files.sh bonus


all:			$(NAME)

.c.o:
				@$(CC) $(CFLAGS) -c -I $(INC_DIR) $< -o $(<:.c=.o)
				@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
				@echo -n "["
				@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
					echo -n "$(G)▰$(X)" ; \
				done
				@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
					echo -n "▱" ; \
				done
				@echo -n "] ($(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%) "
				@echo -n "["
				@printf "%d/%d" $(COMPILED_FILES) $(TOTAL_FILES)
				@echo -n "] "
				@printf "%s" $(notdir $<)
				@printf "\e[0K\r"

$(NAME):		mandatory
				@clear
				@echo "Compilation completed."

mandatory:		title check $(OBJS)
				@make -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKER_FLAGS) ../libft.a
				@clear
				@echo "Mandatories successfully compiled."

bonus:			title check_bonus $(OBJS) $(OBJS_BONUS)
				@make bonus -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_BONUS) $(LINKER_FLAGS) ../libft.a
				@clear
				@echo "Mandatories & Bonus successfully compiled."

ncmandatory:	title $(OBJS)
				@make -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ../libft.a
				@clear
				@echo "Mandatories successfully compiled without check."

ncbonus:		title $(OBJS) $(OBJS_BONUS)
				@make bonus -sC ..
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_BONUS) ../libft.a
				@clear
				@echo "Mandatories & Bonus successfully compiled without check."

clean:
				@make clean -sC ..
				@$(RM) $(OBJS) $(OBJS_BONUS)
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

title:
				@scripts/title.sh
				@printf "\n"

check:
				@if ! $(CHECK_SCRIPT); then \
					exit 1; \
				fi

check_bonus:
				@if ! $(CHECK_BONUS); then \
					exit 1; \
				fi

.PHONY: 		all title mandatory bonus ncmandatory ncbonus clean fclean re title check check_bonus
