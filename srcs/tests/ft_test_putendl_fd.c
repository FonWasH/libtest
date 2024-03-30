/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:32:43 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 17:41:20 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char		*g_eputendl[] = {
	"\t\n\v\f\r \n",
	"Hello World!\n",
	"abcdefghijklmnopqrstuvwxyz\n",
	"42\n",
	"#\n",
	"\n",
	NULL
};

static bool	ft_run_test(char *s, char *e)
{
	int		pipefd[2];
	char	user[BUFFER_SIZE];

	pipe(pipefd);
	ft_time_function(USER_START);
	ft_putendl_fd(s, pipefd[1]);
	ft_time_function(USER_END);
	read(pipefd[0], user, strlen(s) + 1);
	if (strcmp(user, e))
	{
		ft_result_input_str(s, NULL);
		ft_result_output_str(user, e);
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

bool	ft_test_putendl_fd(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_run_test((char *)g_str1_tests[i], (char *)g_eputendl[i]);
		i++;
	}
	return (grade == i);
}
