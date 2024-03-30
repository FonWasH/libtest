/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:32:56 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 19:18:40 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(char *s)
{
	int		pipefd[2];
	char	user[BUFFER_SIZE];

	pipe(pipefd);
	ft_time_function(USER_START);
	ft_putnbr_fd(s, pipefd[1]);
	ft_time_function(USER_END);
	read(pipefd[0], user, strlen(s));
	if (strcmp(user, s))
	{
		ft_result_input_str(s, NULL);
		ft_result_output_str(user, s);
		ft_print_result(false);
		memset(user, 0, sizeof(user));
		close(pipefd[0]);
		close(pipefd[1]);
		return (false);
	}
	memset(user, 0, sizeof(user));
	close(pipefd[0]);
	close(pipefd[1]);
	return (true);
}

bool	ft_test_putnbr_fd(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_run_test((char *)g_str1_tests[i]);
		i++;
	}
	return (grade == i);
}