/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/20 22:28:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_memcpy(char *name, const char **test)
{
	(void)name;
	(void)test;
	/*
	size_t	i = 0;
	size_t	grade = 0;
	char	user[] = "                ";
	char	orig[] = "                ";
	bool	success;

	(void)name;
	while (test[i])
	{
		ft_memcpy(user, test[i], strlen(test[i]));
		memcpy(orig, test[i], strlen(test[i]));
		success = (!strcmp(user, orig));
		ft_print_test_strstr(test[i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
	*/
}
