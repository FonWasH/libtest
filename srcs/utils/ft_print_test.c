/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:19:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:11:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_putchar_isprint(char c, bool newline)
{
	printf("'");
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'%s", newline ? "\n" : "");
}

static void	ft_putstr_isprint(const char *str, bool newline)
{
	printf("\"");
	while (*str)
	{
		if (isprint(*str))
			printf("%c", *str);
		else
			printf("\\%02x", (unsigned char)*str);
		str++;
	}
	printf("\"%s", newline ? "\n" : "");
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

void	ft_print_test_chrint(const char test, int user, int orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putchar_isprint(test, true);
	printf("%s%i%s%s%i\n", USER, user, SEP, ORIG, orig);
}

void	ft_print_test_chrstr(const char test, char *user, char *orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putchar_isprint(test, true);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s%s", SEP, ORIG);
	ft_putstr_isprint(orig, true);
}

void	ft_print_test_strint(const char *test, int user, int orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putstr_isprint(test, true);
	printf("%s%i%s%s%i\n", USER, user, SEP, ORIG, orig);
}

void	ft_print_test_strstr(const char *test, char *user, char *orig)
{
	printf("%s%s => ", TEST, KO);
	ft_putstr_isprint(test, true);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s%s", SEP, ORIG);
	ft_putstr_isprint(orig, true);
}

void	ft_print_test_intstr(int test, char *user, char *orig)
{
	printf("%s%s => %i\n", TEST, KO, test);
	printf("%s", USER);
	ft_putstr_isprint(user, false);
	printf("%s%s", SEP, ORIG);
	ft_putstr_isprint(orig, true);
}
