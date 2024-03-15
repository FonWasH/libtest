/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:26:25 by juperez           #+#    #+#             */
/*   Updated: 2024/03/15 09:37:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

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

void	ft_putchar_isprint(char c, bool newline)
{
	printf("'");
	if (isprint(c))
		printf("%c", c);
	else
		printf("\\%02x", (unsigned char)c);
	printf("'%s", newline ? "\n" : "");
}

bool	ft_norminette(char *name)
{
	char	cmd[100] = "norminette -o ../";
	char	ext[] = ".c > /dev/null 2>&1";

	strcat(cmd, name);
	strcat(cmd, ext);
	if (!system(cmd))
	{
		printf("norminette : %s\n", OK);
		return (true);
	}
	else
	{
		printf("norminette : %s\n", ERROR);
		return (false);
	}
}
