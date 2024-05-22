/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:18:39 by juperez           #+#    #+#             */
/*   Updated: 2024/05/22 01:24:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void *user_dest, const void *user_src, void *libc_dest, const void *libc_src, size_t n)
{
	ft_time_function(USER_START);
	ft_memmove(user_dest, user_src, n);
	ft_time_function(USER_END_LIBC_START);
	memmove(libc_dest, libc_src, n);
	ft_time_function(LIBC_END);
	if (strcmp(user_dest, libc_dest))
		return (false);
	return (true);
}

static bool	ft_test_ptr_pos(void *user, void *libc, size_t n, size_t *pos)
{
	*pos = 1;
	if (!ft_run_test(user, (const void *)user, libc, (const void *)libc, n))
		return (false);
	*pos = 2;
	if (!ft_run_test(user, (const void *)user + 5, libc, (const void *)libc + 5, n))
		return (false);
	*pos = 3;
	if (!ft_run_test(user + 6, (const void *)user, libc + 6, (const void *)libc, n))
		return (false);
	return (true);
}

bool	ft_test_memmove(char *name)
{
	char	user[] = "abcdefghijklmnopqrst";
	char	libc[] = "abcdefghijklmnopqrst";
	size_t	i = 0, grade = 0, pos;
	bool	success;

	(void)name;
	while (i < 10)
	{
		success = ft_test_ptr_pos((void *)user, (void *)libc, i, &pos);	
		if (!success)
		{
			ft_result_input_sizet(i);
			ft_result_output_str((char *)user, (char *)libc);
			ft_print_result(true);
			printf("%s%s", MEM, pos == 1 ? EQU : pos == 2 ? HIG : LOW);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
