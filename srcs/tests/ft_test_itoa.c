/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:58 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:38:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_itoa(char *name, const char **test)
{
	size_t	i = 0;
	size_t	grade = 0;
	char	*user;
	bool	success;

	(void)name;
	while (test[i])
	{
		user = ft_itoa(atoi(test[i]));
		success = (!strcmp(user, test[i]));
		ft_print_test_strstr(test[i], user, (char *)test[i], success);
		grade += success;
		free(user);
		i++;
	}
	return (grade == i);
}
