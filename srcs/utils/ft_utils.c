/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/24 16:57:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_build_cmd(char *target, size_t len, char *cmd_start, char *cmd_end)
{
	char	*cmd = NULL;
	size_t	cmd_len = strlen(cmd_start) + len + strlen(cmd_end);
	bool	success = false;

	cmd = (char *)malloc(sizeof(char) * cmd_len + 1);
	if (!cmd)
	{
		fprintf(stderr, ERROR_MEM);
		exit(EXIT_FAILURE);
	}
	cmd[cmd_len] = '\0';
	snprintf(cmd, cmd_len + 1, "%s%s%s", cmd_start, target, cmd_end);
	success = (!system(cmd));
	free(cmd);
	return (success);
}

static void	ft_print_name(char *name, int len)
{
	int	space = (SIZE_LINE - len - 2) / 2;

	printf("%.*s %s%s%s%s %.*s\n", space, LINE, B, BD, name, X, SIZE_LINE - space - len, LINE);
}

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
		printf("%s%s%s%fs%s%s%s%fs%s\n", TIME, USER, DM, user_time, X, ORIG, DM, orig_time, X);
		user_time = 0;
		orig_time = 0;
	}
}

bool	ft_test_norminette(char *name)
{
	size_t	len = strlen(name);
	bool	success = ft_build_cmd(name, len, CMD_NS, CMD_NE);

	ft_print_name(name, (int)len);
	printf("%s%s\n", NORME, success ? OK : ERROR);
	if (!success)
		printf("%s%s\n", GRADE, FAIL);
	return (success);
}

bool	ft_check_sysfunc(char *name)
{
	bool	success = ft_build_cmd(name, strlen(name), CMD_CS, CMD_CE);

	printf("%s%s\n", FORFUNC, success ? OK : ERROR);
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
