/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:18:39 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 11:36:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memmove_size(void *user, void *libc, size_t size, size_t *step)
{
	*step = 1;
	ft_time_function(USER_START);
	ft_memmove(user, (const void *)user, size);
	ft_time_function(USER_END_LIBC_START);
	memmove(libc, (const void *)libc, size);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
			return (false);
	*step = 2;
	ft_time_function(USER_START);
	ft_memmove(user, (const void *)user + 5, size);
	ft_time_function(USER_END_LIBC_START);
	memmove(libc, (const void *)libc + 5, size);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
			return (false);
	*step = 3;
	ft_time_function(USER_START);
	ft_memmove(user + 6, (const void *)user, size);
	ft_time_function(USER_END_LIBC_START);
	memmove(libc + 6, (const void *)libc, size);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
			return (false);
	return (true);
}

bool	ft_test_memmove(char *name, void **test)
{
	size_t	size[] = {0, 1, 5, 10};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]), step;
	char	user[] = "abcdefghijklmnopqrst", libc[] = "abcdefghijklmnopqrst";
	bool	success;

	(void)name;
	(void)test;
	while (i < count)
	{
		success = ft_test_memmove_size((void *)user, (void *)libc, size[i], &step);	
		if (!success)
		{
			ft_result_input_sizet(size[i]);
			ft_result_output_str((char *)user, (char *)libc);
			ft_print_result(true);
			printf("%s%s", MEM_FAIL, step == 1 ? EQUAL : step == 2 ? HIGHER : LOWER);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
