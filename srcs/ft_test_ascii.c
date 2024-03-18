/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 13:35:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_find_test_ascii(char *name, char test, int *user, int *orig)
{
	size_t	i;

	i = 0;
	while (g_fascii[i].name)
	{
		if (!strcmp(name, g_fascii[i].name))
		{
			*user = (*g_fascii[i].user)(test);
			*orig = (*g_fascii[i].orig)(test);
			if (g_fascii[i].equal)
				return (*orig == *user);
			else
				return ((*orig && *user) || (!*orig && !*user));
		}
		i++;
	}
	fprintf(stderr, "Error: Function does not exist");
	exit(EXIT_FAILURE);
}

bool	ft_test_ascii(char *name, const char **test)
{
	int		grade;
	int		i;
	int		user;
	int		orig;
	bool	success;

	grade = 0;
	i = 0;
	while (test[0][i])
	{
		success = ft_find_test_ascii(name, test[0][i], &user, &orig);
		ft_print_test_chrint(test[0][i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
