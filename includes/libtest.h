/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:25:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include "../../libft.h"
# include <ctype.h>
# include <libgen.h>
# include <stdbool.h>
# include <stdio.h>

# define BUFFER_SIZE 1024

# define R "\033[0;31m"
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define X "\033[0m"

# define ERROR "\033[0;31mERROR\033[0m"
# define KO "\033[0;31mKO\033[0m"
# define OK "\033[0;32mOK\033[0m"
# define FAIL "\033[0;31mFAIL\033[0m :("
# define SUCCESS "\033[0;32mSUCCESS\033[0m :)"

# define TRY_HELP "Try '--help' for more information.\n"
# define CMD_SHOW "find ../ -maxdepth 1 -type f -name 'ft_*.c'-exec basename {} \\; | sed -e 's/.c$//' | sort"

# define CHAR_TEST "09AZaz#\n😀"

extern const char	*g_atoi_tests[];
extern const char	*g_itoa_tests[];
extern const char	*g_str_tests[];

void	ft_putstr_isprint(const char *str, bool newline);
void	ft_putchar_isprint(char c, bool newline);
bool	ft_norminette(char *name);
void	ft_print_file(char *path);
void	ft_all_mandatory(void);
void	ft_all_bonus(void);
bool	ft_check_argument(char *arg, const char **test, int count);
void	ft_test_ascii(char *name, const char *test, int (*ft_user)(int),
			int (*ft_orig)(int));
void	ft_test_strlen(char *name, const char **test,
			size_t (*ft_user)(const char *), size_t (*ft_orig)(const char *));
void	ft_test_strdup(char *name, const char **test,
			char *(*ft_user)(const char *), char *(*ft_orig)(const char *));
void	ft_test_atoi(char *name, const char **test,
			int (*ft_user)(const char *), int (*ft_orig)(const char *));
void	ft_test_itoa(char *name, const char **test, char *(*ft_user)(int));

#endif
