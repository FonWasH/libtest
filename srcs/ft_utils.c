/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 12:29:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_putstr_isprint(const char *str, bool newline)
{
	printf("\"");
	while (*str)
	{
		if (isprint(*str))
			printf("%c", *str);
		else
			printf("\\%02x", (unsigned char)*str);
		str++;
	}
	printf("\"");
	if (newline)
		printf("\n");
}

void	ft_putchar_isprint(char c, bool newline)
{
	printf("'");
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'");
	if (newline)
		printf("\n");
}

bool	ft_test_norminette(char *name)
{
	char	*cmd;
	size_t	cmd_len;
	bool	success;

	cmd_len = strlen(CMD_NS) + strlen(name) + strlen(CMD_NE);
	cmd = (char *)malloc(sizeof(char) * cmd_len + 1);
	if (!cmd)
	{
		fprintf(stderr, "Error: Memory allocation");
		exit(EXIT_FAILURE);
	}
	cmd[cmd_len] = '\0';
	sprintf(cmd, "%s%s%s", CMD_NS, name, CMD_NE);
	success = false;
	if (!system(cmd))
		success = true;
	free(cmd);
	printf("-- %s%s%s --\nnorminette: ", Y, name, X);
	if (success)
		printf("%s\n", OK);
	else
		printf("%s\n", ERROR);
	return (success);
}

void	ft_print_file(char *path)
{
	FILE	*file;
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;

	file = fopen(path, "r");
	if (!file)
		return ;
	bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
	while (bytes_read > 0)
	{
		fwrite(buffer, 1, bytes_read, stdout);
		bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
	}
	fclose(file);
}
