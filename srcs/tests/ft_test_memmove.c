/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:18:39 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 07:36:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memmove_size(char *user, char *orig, size_t size, size_t *step)
{
	*step = 1;
	ft_time_function(USER_START);
	ft_memmove(user, (const char *)user, size);
	ft_time_function(USER_END_ORIG_START);
	memmove(orig, (const char *)orig, size);
	ft_time_function(ORIG_END);
	if (strcmp(user, orig))
			return (false);
	*step = 2;
	ft_time_function(USER_START);
	ft_memmove(user, (const char *)user + 5, size);
	ft_time_function(USER_END_ORIG_START);
	memmove(orig, (const char *)orig + 5, size);
	ft_time_function(ORIG_END);
	if (strcmp(user, orig))
			return (false);
	*step = 3;
	ft_time_function(USER_START);
	ft_memmove(user + 6, (const char *)user, size);
	ft_time_function(USER_END_ORIG_START);
	memmove(orig + 6, (const char *)orig, size);
	ft_time_function(ORIG_END);
	if (strcmp(user, orig))
			return (false);
	return (true);
}

bool	ft_test_memmove(char *name, void **test)
{
	size_t	size[] = {0, 1, 5, 10};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]), step;
	char	user[] = "abcdefghijklmnopqrst", orig[] = "abcdefghijklmnopqrst";
	bool	success;

	(void)name;
	(void)test;
	while (i < count)
	{
		success = ft_test_memmove_size(user, orig, size[i], &step);	
		if (!success)
		{
			ft_print_test_intstr(size[i], user, orig);
			printf("%s%s\n", MEM_FAIL, step == 1 ? EQUAL : step == 2 ? HIGHER : LOWER);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
