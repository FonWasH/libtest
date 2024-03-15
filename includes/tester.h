/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:17:48 by juperez           #+#    #+#             */
/*   Updated: 2024/03/15 09:48:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "../../libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <ctype.h>

# define R "\033[0;31m"
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define X "\033[0m"

# define ERROR "\033[0;31mERROR\033[0m"
# define KO "\033[0;31mKO\033[0m"
# define OK "\033[0;32mOK\033[0m"

# define FAIL "\033[0;31mFAIL\033[0m :("
# define SUCCESS "\033[0;32mSUCCESS\033[0m :)"

# define CHAR_TEST "09AZaz#\n😀"

void	ft_putstr_isprint(const char *str, bool newline);
void	ft_putchar_isprint(char c, bool newline);
bool	ft_norminette(char *name);
void	ft_test_ascii(
			char *name, char *test, int (*ft_user)(int), int (*ft_orig)(int));
void	ft_test_strlen(
			char *name, const char **test,
			size_t (*ft_user)(const char *), size_t (*ft_orig)(const char *));
void	ft_test_strdup(
			char *name, const char **test,
			char *(*ft_user)(const char *), char *(*ft_orig)(const char *));
void	ft_test_atoi(
			char *name, const char **test,
			int (*ft_user)(const char *), int (*ft_orig)(const char *));
void	ft_test_itoa(char *name, const char **test, char *(*ft_user)(int));

#endif
