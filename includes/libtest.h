/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/05/19 16:50:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

// LIB
# include "../../libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <libgen.h>
# include <limits.h>
# include <string.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdio.h>
# include <time.h>

// BUFFER
# define BUFFER_SIZE 1024

// COLOR
# define R "\e[91m"
# define G "\e[92m"
# define B "\e[94m"
# define Y "\e[33m"
# define BD "\e[1m"
# define DM "\e[2m\e[3m"
# define X "\e[0m"
// STRING
# define KO R "KO\n" X
# define OK G "OK\n" X
# define CHEAT R "CHEAT\n" X
# define ERROR R "ERROR\n" X
# define GRADE_CHEAT R "-42\n" X
# define FAIL R "FAIL" X " :(\n"
# define SUCCESS G "SUCCESS" X " :)\n"
# define NORME BD "Norminette: " X
# define FOR_FUNC BD "Forbidden Functions: " X
# define TEST BD "Test: " X
# define TIME BD "Time: " X
# define GRADE BD "Grade: " X
# define INPUT BD "\tinput:\t" X "=> "
# define OUTPUT BD "\toutput:\t" X "=> "
# define USER "user: "
# define LIBC "libc: "
# define EXPECT "expected: "
# define MEM DM "\t\t   Fail when destination is "
# define HIG "higher\n" X
# define LOW "lower\n" X
# define EQU "equal\n" X
# define LST_FRONT DM "\t\t   Wrong list size\n" X
// FORMAT
# define LINE "--------------------------------------"
# define SIZE_LINE 40
// ERROR
# define ERROR_HELP "\nTry '--help' for more information.\n"
# define ERROR_MEM "Error: Memory allocation\n"
// CMD
# define CMD_NS "norminette -o ../"
# define CMD_NE ".c > /dev/null 2>&1"
# define CMD_CS "./scripts/check_sysfunc.sh ../"
# define CMD_CE ".o > /dev/null 2>&1"
# define CMD_HOST "./scripts/check_hostname.sh"
// PATH
# define TITLE "./scripts/title.sh"
# define SHOW_FUNC "./scripts/show_func.sh"
# define SHOW_HELP "docs/help"
# define SHOW_VERSION "docs/version"

// STRUCT
typedef struct s_ftest
{
	char				*name;
	bool				(*f)(char *);
}						t_ftest;

typedef struct s_fascii
{
	char				*name;
	int					(*user)(int);
	int					(*libc)(int);
}						t_fascii;

typedef struct s_tresult
{
	int					input_int;
	size_t				input_sizet;
	char				input_chr;
	char				*input_str1;
	char				*input_str2;
	int					user_int;
	int					libc_int;
	size_t				user_sizet;
	size_t				libc_sizet;
	char				user_chr;
	char				libc_chr;
	char				*user_str;
	char				*libc_str;
	char				**user_tabstr;
	char				**libc_tabstr;
}						t_result;

typedef struct s_presult
{
	bool				input_int;
	bool				input_sizet;
	bool				input_chr;
	bool				input_str1;
	bool				input_str2;
	bool				output_int;
	bool				output_sizet;
	bool				output_chr;
	bool				output_str;
	bool				output_tabstr;
}						t_presult;

// ENUM
typedef enum e_ftime
{
						RESET,
						USER_START,
						USER_END,
						USER_END_LIBC_START,
						LIBC_START,
						LIBC_END,
						PRINT
}						t_ftime;

// GLOBALS
extern t_presult		g_presult;
extern t_result			g_result;
extern const t_ftest	g_fmandatory[];
extern const t_ftest	g_fbonus[];
extern const char		*g_str1_tests[];
extern const char		*g_str2_tests[];
extern const char		*g_nbr_tests[];

// UTIL FUNCTIONS
void					ft_print_name(char *name);
void					ft_print_file(char *path);
bool					ft_test_norminette(char *name);
bool					ft_check_sysfunc(char *name);
void					ft_time_function(t_ftime action);
void					ft_print_result(bool print_libc);
void					ft_reset_presult(void);
void					ft_result_input_int(int intput);
void					ft_result_input_sizet(size_t intput);
void					ft_result_input_chr(char intput);
void					ft_result_input_str(char *str1, char *str2);
void					ft_result_output_int(int user, int libc);
void					ft_result_output_sizet(size_t user, size_t libc);
void					ft_result_output_chr(char user, char libc);
void					ft_result_output_str(char *user, char *libc);
void					ft_result_output_tabstr(char **user, char **libc);
void					ft_grade(bool success);
void					free_lst(t_list *lst);
size_t					lst_size(t_list *lst);
// MAIN FUNCTIONS
bool					ft_call_test(char *name);
void					ft_call_all_test(bool title, bool force, const t_ftest *ftest);
// TEST FUNCTIONS
bool					ft_test_ascii(char *name);
bool					ft_test_strlen(char *name);
bool					ft_test_memset(char *name);
bool					ft_test_bzero(char *name);
bool					ft_test_memcpy(char *name);
bool					ft_test_memmove(char *name);
bool					ft_test_strlcpy(char *name);
bool					ft_test_strlcat(char *name);
bool					ft_test_strchr(char *name);
bool					ft_test_strrchr(char *name);
bool					ft_test_strncmp(char *name);
bool					ft_test_memchr(char *name);
bool					ft_test_memcmp(char *name);
bool					ft_test_strnstr(char *name);
bool					ft_test_atoi(char *name);
bool					ft_test_calloc(char *name);
bool					ft_test_strdup(char *name);
bool					ft_test_substr(char *name);
bool					ft_test_strjoin(char *name);
bool					ft_test_strtrim(char *name);
bool					ft_test_split(char *name);
bool					ft_test_itoa(char *name);
bool					ft_test_strmapi(char *name);
bool					ft_test_striteri(char *name);
bool					ft_test_putchar_fd(char *name);
bool					ft_test_putstr_fd(char *name);
bool					ft_test_putendl_fd(char *name);
bool					ft_test_putnbr_fd(char *name);
// TEST BONUS FUNCTIONS
bool					ft_test_lstnew(char *name) __attribute__((weak));
bool					ft_test_lstadd_front(char *name) __attribute__((weak));
bool					ft_test_lstsize(char *name) __attribute__((weak));
//bool					ft_test_lstlast(char *name) __attribute__((weak));
//bool					ft_test_lstadd_back(char *name) __attribute__((weak));
//bool					ft_test_lstdelone(char *name) __attribute__((weak));
//bool					ft_test_lstclear(char *name) __attribute__((weak));
//bool					ft_test_lstiter(char *name) __attribute__((weak));
//bool					ft_test_lstmap(char *name) __attribute__((weak));

#endif
