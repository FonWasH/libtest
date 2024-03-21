/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/20 22:37:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_putchar_isprint(char c, bool newline)
{
	printf("'");
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'%s", newline ? "\n" : "");
}

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
	printf("\"%s", newline ? "\n" : "");
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
	printf("-- %s%s%s --\n%snorminette: %s\n", Y, name, X, W, success ? OK : ERROR);
	return (success);
}

void	ft_print_file(char *path)
{
	FILE	*file = fopen(path, "r");
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;

	if (!file)
		return ;
	while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
		fwrite(buffer, 1, bytes_read, stdout);
	fclose(file);
}
