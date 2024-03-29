/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:43 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 13:24:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_calloc(char *name, void **test)
{
	size_t		nmemb[] = {0, 10, 0, 10, 100}; //SIZE_MAX
	size_t		size[] = {0, 0, 10, 10, 100};
	size_t		i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]);
	size_t 		isize;
	char		*user, *libc;
	char 		str_nmemb[64], str_size[64];
	bool		success;

	(void)name;
	(void)test;
	while (i < count)
	{
		ft_time_function(USER_START);
		user = (char *)ft_calloc(nmemb[i], size[i]);
		ft_time_function(USER_END_LIBC_START);
		libc = (char *)calloc(nmemb[i], size[i]);
		ft_time_function(LIBC_END);
		isize = (nmemb[i] && size[i] && (SIZE_MAX / nmemb[i] < size[i])) ? nmemb[i] * size[i] : 1;
		memset((void *)user, '.', isize);
		memset((void *)libc, '.', isize);
		user[isize - 1] = '\0';
		libc[isize - 1] = '\0';
		success = (user && libc && !strcmp(user, libc) && (strlen(user) == strlen(libc)));
		if (!success)
		{
			sprintf(str_nmemb, "%zu", nmemb[i]);
			sprintf(str_size, "%zu", size[i]);
			ft_result_input_str(str_nmemb, str_size);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		free(user);
		free(libc);
		i++;
	}
	return (grade == i);
}
