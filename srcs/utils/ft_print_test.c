/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:19:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 08:33:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_print_grade(bool success)
{
	printf("%sGrade: %s\n", W, success ? SUCCESS : FAIL);
}

void	ft_print_test_chrint(const char test, int user, int orig, bool success)
{
	printf("%s => test: ", success ? OK : KO);
	ft_putchar_isprint(test, true);
	if (!success)
		printf("user: %i | orig: %i\n", user, orig);
}

void	ft_print_test_chrstr(const char test, char *user, char *orig, bool success)
{
	printf("%s => test: ", success ? OK : KO);
	ft_putchar_isprint(test, true);
	if (!success)
	{
		printf("user: ");
		ft_putstr_isprint(user, false);
		printf(" | orig: ");
		ft_putstr_isprint(orig, true);
	}
}

void	ft_print_test_strint(const char *test, int user, int orig, bool success)
{
	printf("%s => test: ", success ? OK : KO);
	ft_putstr_isprint(test, true);
	if (!success)
		printf("user: %i | orig: %i\n", user, orig);
}

void	ft_print_test_strstr(const char *test, char *user, char *orig, bool success)
{
	printf("%s => test: ", success ? OK : KO);
	ft_putstr_isprint(test, true);
	if (!success)
	{
		printf("user: ");
		ft_putstr_isprint(user, false);
		printf(" | orig: ");
		ft_putstr_isprint(orig, true);
	}
}
