/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:44:03 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_time_function(t_ftime action)
{
	static clock_t	user_start, orig_start;
	static double	user_time, orig_time;

	if (action == RESET)
	{
		user_time = 0;
		orig_time = 0;
	}
	if (action == USER_START)
		user_start = clock();
	if ((action == USER_END) || (action == USER_END_ORIG_START))
		user_time += ((double)(clock() - user_start)) / CLOCKS_PER_SEC;
	if ((action == ORIG_START) || (action == USER_END_ORIG_START))
		orig_start = clock();
	if (action == ORIG_END)
		orig_time += ((double)(clock() - orig_start)) / CLOCKS_PER_SEC;
	if (action == PRINT)
	{
		printf("%suser = %fs | orig = %fs\n", TIME, user_time, orig_time);
		user_time = 0;
		orig_time = 0;
	}
}

bool	ft_test_norminette(char *name)
{
	char	*cmd = NULL;
	size_t	cmd_len = strlen(CMD_NS) + strlen(name) + strlen(CMD_NE);
	bool	success = false;

	cmd = (char *)malloc(sizeof(char) * cmd_len + 1);
	if (!cmd)
	{
		fprintf(stderr, "Error: Memory allocation\n");
		exit(EXIT_FAILURE);
	}
	cmd[cmd_len] = '\0';
	snprintf(cmd, cmd_len + 1, "%s%s%s", CMD_NS, name, CMD_NE);
	success = (!system(cmd));
	free(cmd);
	printf("-- %s%s%s --\n%s%s\n", Y, name, X, NORME, success ? OK : ERROR);
	if (!success)
		printf("%s%s\n", GRADE, FAIL);
	return (success);
}

void	ft_print_file(char *path)
{
	FILE	*file = fopen(path, "r");
	char	buffer[BUFFER_SIZE];
	size_t	read;

	if (!file)
		return ;
	while ((read = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
		fwrite(buffer, 1, read, stdout);
	fclose(file);
}
