/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:19:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 13:27:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_print_success(bool success)
{
	if (success)
		printf("%s", OK);
	else
		printf("%s", KO);
	printf(" => test: ");
}

void	ft_print_grade(bool success)
{
	printf("Grade: ");
	if (success)
		printf("%s\n", SUCCESS);
	else
		printf("%s\n", FAIL);
}

void	ft_print_test_chrint(
			const char test, int user, int orig, bool success)
{
	ft_print_success(success);
	ft_putchar_isprint(test, true);
	if (!success)
		printf("user: %i | orig: %i\n", user, orig);
}

void	ft_print_test_strint(
			const char *test, int user, int orig, bool success)
{
	ft_print_success(success);
	ft_putstr_isprint(test, true);
	if (!success)
		printf("user: %i | orig: %i\n", user, orig);
}

void	ft_print_test_strstr(
			const char *test, char *user, char *orig, bool success)
{
	ft_print_success(success);
	ft_putstr_isprint(test, true);
	if (!success)
	{
		printf("user: ");
		ft_putstr_isprint(user, false);
		printf(" | orig: ");
		ft_putstr_isprint(orig, true);
	}
}
