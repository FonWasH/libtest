/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:32:17 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 12:36:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(char c)
{
	int		pipefd[2];
	char	user[BUFFER_SIZE];

	pipe(pipefd);
	ft_time_function(USER_START);
	ft_putchar_fd(c, pipefd[1]);
	ft_time_function(USER_END);
	read(pipefd[0], user, BUFFER_SIZE);
	if (!(user[0] == c))
	{
		ft_result_input_chr(c);
		ft_result_output_chr(user[0], c);
		ft_print_result(false);
		close(pipefd[0]);
		close(pipefd[1]);
		return (false);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (true);
}

bool	ft_test_putchar_fd(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[1][i])
	{
		grade += ft_run_test(g_str1_tests[1][i]);
		i++;
	}
	return (grade == i);
}
