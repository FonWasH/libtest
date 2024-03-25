/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 12:36:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

// LIB
# include "../../libft.h"
# include <ctype.h>
# include <libgen.h>
# include <string.h>
# include <stdbool.h>
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
# define KO R "KO" X
# define OK G "OK" X
# define CHEAT R "CHEAT" X
# define ERROR R "ERROR" X
# define GRADE_CHEAT R "-42" X
# define FAIL R "FAIL" X " :("
# define SUCCESS G "SUCCESS" X " :)"
# define NORME BD "Norminette: " X
# define FOR_FUNC BD "Forbidden Functions: " X
# define TEST BD "Test: " X
# define TIME BD "Time: " X
# define GRADE BD "Grade: " X
# define USER "user: "
# define ORIG " | orig: "
# define MEM_FAIL DM "Fail when destination is "
# define HIGHER "higher" X
# define LOWER "lower" X
# define EQUAL "equal" X
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
// PATH
# define TITLE "./scripts/title.sh"
# define SHOW_FUNC "./scripts/show_func.sh"
# define SHOW_HELP "docs/help"
# define SHOW_VERSION "docs/version"

// STRUCT
typedef struct s_ftest
{
	char				*name;
	bool				(*f)(char *, void **);
}						t_ftest;

typedef struct s_fascii
{
	char				*name;
	int					(*user)(int);
	int					(*orig)(int);
}						t_fascii;

// ENUM
typedef enum e_ftime
{
						RESET,
						USER_START,
						USER_END,
						USER_END_ORIG_START,
						ORIG_START,
						ORIG_END,
						PRINT
}						t_ftime;

// GLOBALS
extern const char		*g_atoi_tests[];
extern const char		*g_itoa_tests[];
extern const char		*g_str_tests[];
extern const char		*g_chr_tests[];
extern const t_ftest	g_ftest[];

// UTIL FUNCTIONS
void					ft_time_function(t_ftime action);
bool					ft_test_norminette(char *name);
bool					ft_check_sysfunc(char *name);
void					ft_print_file(char *path);
void					ft_print_grade(bool success);
void					ft_print_test_chrint(const char test, int user, int orig);
void					ft_print_test_chrstr(const char test, char *user, char *orig);
void					ft_print_test_strint(const char *test, int user, int orig);
void					ft_print_test_strstr(const char *test, char *user, char *orig);
void					ft_print_test_intstr(int test, char *user, char *orig);
// MAIN FUNCTIONS
void					ft_mandatory(bool title);
void					ft_bonus(bool title);
bool					ft_call_test(char *name, void **test, int count);
// TEST FUNCTIONS
bool					ft_test_ascii(char *name, void **test);
bool					ft_test_strlen(char *name, void **test);
bool					ft_test_strdup(char *name, void **test);
bool					ft_test_atoi(char *name, void **test);
bool					ft_test_itoa(char *name, void **test);
bool					ft_test_memset(char *name, void **test);
bool					ft_test_bzero(char *name, void **test);
bool					ft_test_memcpy(char *name, void **test);
bool					ft_test_memmove(char *name, void **test);

#endif
