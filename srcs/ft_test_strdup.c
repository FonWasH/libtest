/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:49:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 12:58:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strdup(char *name, const char **test)
{
	int		grade;
	int		i;
	char	*user;
	char	*orig;
	bool	success;	

	(void)name;
	grade = 0;
	i = 0;
	while (test[i])
	{
		user = ft_strdup(test[i]);
		orig = strdup(test[i]);
		success = (!strcmp(user, orig) && (strlen(user) == strlen(orig)));
		ft_print_test_strstr(test[i], user, orig, success);
		grade += success;
		free(user);
		free(orig);
		i++;
	}
	return (grade == i);
}
