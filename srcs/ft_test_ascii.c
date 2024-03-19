/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:47:15 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_find_test_ascii(char *name, char test, int *user, int *orig)
{
	for (size_t i = 0; g_fascii[i].name; i++)
	{
		if (!strcmp(name, g_fascii[i].name))
		{
			*user = (*g_fascii[i].user)(test);
			*orig = (*g_fascii[i].orig)(test);
			return (g_fascii[i].equal ?
				(*orig == *user) : ((*orig && *user) || (!*orig && !*user)));
		}
	}
	fprintf(stderr, "Error: Function does not exist\n");
	exit(EXIT_FAILURE);
}

bool	ft_test_ascii(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	int		user;
	int		orig;
	bool	success;

	while (test[0][i])
	{
		success = ft_find_test_ascii(name, test[0][i], &user, &orig);
		ft_print_test_chrint(test[0][i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
