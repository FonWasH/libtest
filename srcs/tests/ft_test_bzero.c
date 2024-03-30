/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:37 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(size_t n)
{
	char	user[] = "................";
	char	libc[] = "................";

	ft_time_function(USER_START);
	ft_bzero((void *)user, n);
	ft_time_function(USER_END_LIBC_START);
	bzero((void *)libc, n);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
	{
		ft_result_input_sizet(n);
		ft_result_output_str(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

bool	ft_test_bzero(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (i < 16)
	{
		grade += ft_run_test(i);
		i++;
	}
	return (grade == i);
}
