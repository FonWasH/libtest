/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 12:01:22 by juperez          ###   ########.fr       */
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

bool	ft_test_norminette(char *name)
{
	size_t	len = strlen(name);
	bool	success = ft_build_cmd(name, len, CMD_NS, CMD_NE);

	ft_print_name(name, (int)len);
	printf("%s%s", NORME, success ? OK : ERROR);
	if (!success)
		printf("%s%s", GRADE, FAIL);
	return (success);
}

bool	ft_check_sysfunc(char *name)
{
	bool	success = ft_build_cmd(name, strlen(name), CMD_CS, CMD_CE);

	printf("%s%s", FOR_FUNC, success ? OK : CHEAT);
	if (!success)
		printf("%s%s", GRADE, GRADE_CHEAT);
	return (success);
}

void	ft_time_function(t_ftime action)
{
	static clock_t	user_start, libc_start;
	static double	user_time, libc_time;

	if (action == RESET)
	{
		user_time = 0;
		libc_time = 0;
	}
	if (action == USER_START)
		user_start = clock();
	if ((action == USER_END) || (action == USER_END_LIBC_START))
		user_time += ((double)(clock() - user_start)) / CLOCKS_PER_SEC;
	if ((action == LIBC_START) || (action == USER_END_LIBC_START))
		libc_start = clock();
	if (action == LIBC_END)
		libc_time += ((double)(clock() - libc_start)) / CLOCKS_PER_SEC;
	if (action == PRINT)
	{
		printf("%s%s%s%fs%s | %s%s%fs%s\n", TIME, USER, DM, user_time, X, LIBC, DM, libc_time, X);
		user_time = 0;
		libc_time = 0;
	}
}
