/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:07:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

// LIB
# include "../../libft.h"
# include <ctype.h>
# include <libgen.h>
# include <stdbool.h>
# include <stdio.h>
# include <time.h>

// BUFFER
# define BUFFER_SIZE 1024

// COLOR
# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define W "\033[1;37m"
# define X "\033[0m"

// STRING
# define KO R "KO" X
# define OK G "OK" X
# define FAIL R "FAIL" X " :("
# define SUCCESS G "SUCCESS" X " :)"
# define ERROR R "ERROR" X
# define USER W "user: " X
# define ORIG W "orig: " X
# define SEP W " | " X
# define NORME W "Norminette: " X
# define TEST W "Test: " X
# define TIME W "Time: " X
# define GRADE W "Grade: " X
# define HELP "\nTry '--help' for more information.\n"

// CMD
# define CMD_NS "norminette -o ../"
# define CMD_NE ".c > /dev/null 2>&1"

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
}	t_ftime;

// GLOBALS
extern const char		*g_atoi_tests[];
extern const char		*g_itoa_tests[];
extern const char		*g_str_tests[];
extern const char		*g_char_tests[];
extern const char		*g_memset_tests[];
extern const t_ftest	g_ftest[];

// UTIL FUNCTIONS
void					ft_time_function(t_ftime action);
bool					ft_test_norminette(char *name);
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