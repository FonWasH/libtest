/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:26:37 by juperez           #+#    #+#             */
/*   Updated: 2024/03/27 15:47:58 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strchr(char *name, void **test)
{
	const char	*tests = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0;
	char		user[] = "DEST\0................", orig[] = "DEST\0................";
	bool		success;

	(void)name;
	while (i < count)
	{
		ft_time_function(USER_START);
		user = ft_strchr(user, tests, size[i]);
		ft_time_function(USER_END_ORIG_START);
		orig = strchr(orig, tests, size[i]);
		ft_time_function(ORIG_END);
		success = (!strcmp(user, orig));
		if (!success)
			ft_print_fail_chrstrstr();
		grade += success;
		i++;
	}
	return (grade == i);
}
