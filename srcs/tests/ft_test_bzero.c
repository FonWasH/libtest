/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:07:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/20 21:21:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_bzero(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	char	user[] = "                ";
	char	orig[] = "                ";
	size_t	size[] = {0, 1, 8, 16};
	size_t	count = sizeof(size) / sizeof(size[0]);
	bool	success;

	(void)name;
	(void)test;
	while (i < count)
	{
		ft_bzero(user, size[i]);
		bzero(orig, size[i]);
		success = (!strcmp(user, orig));
		ft_print_test_intstr((int)size[i], user, orig, success);
		grade += success;
		i++;
	}
	return (grade == i);
}
