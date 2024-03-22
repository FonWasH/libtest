/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:27:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_bzero(char *name, void **test)
{
	size_t	size[] = {0, 1, 8, 16};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]);
	char	user[] = "                ", orig[] = "                ";
	bool	success;

	(void)name;
	(void)test;
	while (i < count)
	{
		ft_time_function("user_start");
		ft_bzero(user, size[i]);
		ft_time_function("user_end orig_start");
		bzero(orig, size[i]);
		ft_time_function("orig_end");
		success = (!strcmp(user, orig));
		if (!success)
			ft_print_test_intstr((int)size[i], user, orig);
		grade += success;
		i++;
	}
	return (grade == i);
}
