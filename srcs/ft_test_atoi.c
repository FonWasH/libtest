/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:50 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 12:55:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_atoi(char *name, const char **test)
{
	int		grade;
	int		i;
	int		user;
	int		orig;
	bool	success;	

	(void)name;
	grade = 0;
	i = 0;
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
