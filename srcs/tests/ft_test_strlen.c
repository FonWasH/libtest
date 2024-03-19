/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:40:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlen(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	size_t	user;
	size_t	orig;
	bool	success;	

	(void)name;
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
