/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:06:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/20 22:40:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memset_size(char *user, char *orig, char c)
{
	size_t	size[] = {0, 1, 8, 16};
	size_t	count = sizeof(size) / sizeof(size[0]);

	for (size_t i = 0; i < count; i++)
	{
		ft_memset(user, c, size[i]);
		memset(orig, c, size[i]);
		if (strcmp(user, orig))
			return (false);
	}
	return (true);
}

bool	ft_test_memset(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	char	user[] = "                ";
	char	orig[] = "                ";
	bool	success;

	(void)name;
	while (test[0][i])
	{
		success = ft_test_memset_size(user, orig, test[0][i]);
		ft_print_test_chrstr(test[0][i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
