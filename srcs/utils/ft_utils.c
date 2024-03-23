/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/23 12:54:11 by juperez          ###   ########.fr       */
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
		printf("%s%s%s%fs%s%s%s%fs%s\n", TIME, USER, DM, user_time, X, ORIG, DM, orig_time, X);
		user_time = 0;
		orig_time = 0;
	}
}

void	ft_print_name(char *name, int len)
{
	int	space = (SIZE_LINE - len - 2) / 2;
	
	printf("%.*s %s%s%s%s %.*s\n", space, LINE, B, BD, name, X, SIZE_LINE - space - len, LINE);
}

bool	ft_test_norminette(char *name)
{
	char	*cmd = NULL;
	size_t	len = strlen(name), cmd_len = strlen(CMD_NS) + len + strlen(CMD_NE);
	bool	success = false;

	cmd = (char *)malloc(sizeof(char) * cmd_len + 1);
	if (!cmd)
	{
		fprintf(stderr, ERROR_MEM);
		exit(EXIT_FAILURE);
	}
	cmd[cmd_len] = '\0';
	snprintf(cmd, cmd_len + 1, "%s%s%s", CMD_NS, name, CMD_NE);
	success = (!system(cmd));
	free(cmd);
	ft_print_name(name, (int)len);
	printf("%s%s\n", NORME, success ? OK : ERROR);
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
