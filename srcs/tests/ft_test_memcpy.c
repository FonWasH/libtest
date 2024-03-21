/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/21 00:29:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_memcpy(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	char	*user;
	char	*orig;
	size_t	test_len;
	bool	success;

	(void)name;
	while (test[i])
	{
		test_len = strlen(test[i]);
		user = (char *)malloc(sizeof(char) * test_len + 1);
		orig = (char *)malloc(sizeof(char) * test_len + 1);
		if (!user || !orig)
		{
			fprintf(stderr, "Error: Memory allocation\n");
			exit(EXIT_FAILURE);
		}
		user[test_len] = '\0';
		orig[test_len] = '\0';
		ft_memcpy(user, test[i], strlen(test[i]));
		memcpy(orig, test[i], strlen(test[i]));
		success = (!strcmp(user, orig));
		ft_print_test_strstr(test[i], user, orig, success);
		grade += success;
		free(user);
		free(orig);
		i++;
	}
	return (grade == i);
}
