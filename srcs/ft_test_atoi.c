/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:50 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:37:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_atoi(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	int		user;
	int		orig;
	bool	success;	

	(void)name;
	while (test[i])
	{
		user = ft_atoi(test[i]);
		orig = atoi(test[i]);
		success = (user == orig);
		ft_print_test_strint(test[i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
