/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:18:39 by juperez           #+#    #+#             */
/*   Updated: 2024/03/21 04:07:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memmove_size(char *user, char *orig, size_t size, size_t *step)
{
	*step = 1;
	ft_memmove(user, (const char *)user, size);
	memmove(orig, (const char *)orig, size);
	if (strcmp(user, orig))
			return (false);
	*step = 2;
	ft_memmove(user, (const char *)user + 5, size);
	memmove(orig, (const char *)orig + 5, size);
	if (strcmp(user, orig))
			return (false);
	*step = 3;
	ft_memmove(user + 6, (const char *)user, size);
	memmove(orig + 6, (const char *)orig, size);
	if (strcmp(user, orig))
			return (false);
	return (true);
}

bool	ft_test_memmove(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	char	user[] = "abcdefghijklmnopqrst";
	char	orig[] = "abcdefghijklmnopqrst";
	size_t	size[] = {0, 1, 5, 10};
	size_t	count = sizeof(size) / sizeof(size[0]);
	size_t	step;
	bool	success;

	(void)name;
	(void)test;
	while (i < count)
	{
		success = ft_test_memmove_size(user, orig, size[i], &step);	
		ft_print_test_intstr(size[i], user, orig, success);
		if (!success)
		printf("Fail when destination is %s\n", step == 1 ? "equal" : step == 2 ? "higher" : "lower");
		grade += success;
		i++;
	}
	return (grade == i);
}
