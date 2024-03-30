/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:43 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:38 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(size_t nmemb, size_t size)
{
	size_t	i = (nmemb && size && (SIZE_MAX / nmemb < size)) ? nmemb * size : 1;
	char 	str_nmemb[21], str_size[21];
	char	*user, *libc;

	ft_time_function(USER_START);
	user = (char *)ft_calloc(nmemb, size);
	ft_time_function(USER_END_LIBC_START);
	libc = (char *)calloc(nmemb, size);
	ft_time_function(LIBC_END);
	memset((void *)user, '.', i);
	memset((void *)libc, '.', i);
	user[i - 1] = '\0';
	libc[i - 1] = '\0';
	if (strcmp(user, libc))
	{
		sprintf(str_nmemb, "%zu", nmemb);
		sprintf(str_size, "%zu", size);
		ft_result_input_str(str_nmemb, str_size);
		ft_result_output_str(user, libc);
		ft_print_result(true);
		free(user);
		free(libc);
		return (false);
	}
	free(user);
	free(libc);
	return (true);
}

bool	ft_test_calloc(char *name)
{
	size_t	nmemb[] = {0, 10, 0, 10, 100}; //SIZE_MAX 18446744073709551615
	size_t	size[] = {0, 0, 10, 10, 100};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]);

	(void)name;
	while (i < count)
	{
		grade += ft_run_test(nmemb[i], size[i]);
		i++;
	}
	return (grade == i);
}
