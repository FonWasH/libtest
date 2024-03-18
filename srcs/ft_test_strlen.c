/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 13:02:21 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlen(char *name, const char **test)
{
	int		grade;
	int		i;
	size_t	user;
	size_t	orig;
	bool	success;	

	(void)name;
	grade = 0;
	i = 0;
	while (test[i])
	{
		user = ft_strlen(test[i]);
		orig = strlen(test[i]);
		success = (user == orig);
		ft_print_test_strint(test[i], (int)user, (int)orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
