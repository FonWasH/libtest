/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 15:45:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_bzero(char *name, void **test)
{
	size_t	i = 0, grade = 0;
	char	user[] = "................", libc[] = "................";
	bool	success;

	(void)name;
	(void)test;
	while (i < 16)
	{
		ft_time_function(USER_START);
		ft_bzero(user, i);
		ft_time_function(USER_END_LIBC_START);
		bzero(libc, i);
		ft_time_function(LIBC_END);
		success = (!strcmp(user, libc));
		if (!success)
		{
			ft_result_input_sizet(i);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
