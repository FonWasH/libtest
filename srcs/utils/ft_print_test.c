/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:19:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_putchar_isprint(char c, bool newline)
{
	printf("%s'", DM);
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'%s%s", X, newline ? "\n" : "");
}

static void	ft_putstr_isprint(const char *str, bool newline)
{
	printf("%s\"", DM);
	while (*str)
	{
		if (isprint(*str))
			printf("%c", *str);
		else
			printf("\\%02x", (unsigned char)*str);
		str++;
	}
	printf("\"%s%s", X, newline ? "\n" : "");
}

void	ft_print_grade(bool success)
{
	if (success)
	{
		printf("%s%s\n", TEST, OK);
		ft_time_function(PRINT);
	}
	printf("%s%s\n", GRADE, success ? SUCCESS : FAIL);
}

void	ft_print_fail_chrint(const char test, int user, int orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putchar_isprint(test, true);
	printf("%s%s%i%s%s%s%i%s\n", USER, DM, user, X, ORIG, DM, orig, X);
}

void	ft_print_fail_chrstr(const char test, char *user, char *orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putchar_isprint(test, true);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s", ORIG);
	ft_putstr_isprint(orig, true);
}

void	ft_print_fail_strint(const char *test, int user, int orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putstr_isprint(test, true);
	printf("%s%s%i%s%s%s%i%s\n", USER, DM, user, X, ORIG, DM, orig, X);
}

void	ft_print_fail_strstr(const char *test, char *user, char *orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putstr_isprint(test, true);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s", ORIG);
	ft_putstr_isprint(orig, true);
}

void	ft_print_fail_intstr(int test, char *user, char *orig)
{
	printf("%s%s => %s%i%s\n", TEST, KO, DM, test, X);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s", ORIG);
	ft_putstr_isprint(orig, true);
}
