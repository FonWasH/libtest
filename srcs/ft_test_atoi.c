/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:50 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:15:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_test_atoi(
			char *name, const char **test,
			int (*ft_user)(const char *), int (*ft_orig)(const char *))
{
	int		i;
	int		user;
	int		orig;
	int		grade;
	bool	success;	

	printf("-- %s%s%s --\n", Y, name, X);
	if (!ft_norminette(name))
		return ;
	grade = 0;
	i = 0;
	while (test[i])
	{
		user = (*ft_user)(test[i]);
		orig = (*ft_orig)(test[i]);
		success = (user == orig) ? true : false;
		printf("%s => test: ", success ? OK : KO);
		ft_putstr_isprint(test[i], true);
		if (!success)
			printf("user: %i | orig: %i\n", user, orig);
		grade += success ? 1 : 0;
		i++;
	}
	printf("Grade: %s\n", grade == i ? SUCCESS : FAIL);
}
