/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:23:07 by juperez          ###   ########.fr       */
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
# define HELP "\nTry '--help' for more information.\n"

// CMD
# define CMD_NS "norminette -o ../"
# define CMD_NE ".c > /dev/null 2>&1"

// STRUCT
typedef struct s_ftest
{
	char				*name;
	bool				(*f)(char *, const char **);
	const char			**test;
}						t_ftest;

typedef struct s_fascii
{
	char				*name;
	int					(*user)(int);
	int					(*orig)(int);
	bool				equal;
}						t_fascii;

// GLOBALS
extern const char		*g_atoi_tests[];
extern const char		*g_itoa_tests[];
extern const char		*g_str_tests[];
extern const char		*g_char_tests[];
extern const t_ftest	g_ftest[];
extern const t_fascii	g_fascii[];

// UTIL FUNCTIONS
void					ft_putstr_isprint(const char *str, bool newline);
void					ft_putchar_isprint(char c, bool newline);
bool					ft_test_norminette(char *name);
void					ft_print_file(char *path);

// MAIN FUNCTIONS
void					ft_all_mandatory(bool title);
void					ft_all_bonus(bool title);
bool					ft_check_argument(
							char *name, const char **test, int count);

// TEST FUNCTIONS
void					ft_print_grade(bool success);
void					ft_print_test_chrint(const char test, int user, int orig, bool success);
void					ft_print_test_strint(const char *test, int user, int orig, bool success);
void					ft_print_test_strstr(const char *test, char *user, char *orig, bool success);
bool					ft_test_ascii(char *name, const char **test);
bool					ft_test_strlen(char *name, const char **test);
bool					ft_test_strdup(char *name, const char **test);
bool					ft_test_atoi(char *name, const char **test);
bool					ft_test_itoa(char *name, const char **test);

#endif
