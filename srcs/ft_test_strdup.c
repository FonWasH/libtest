/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:49:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/17 03:37:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_test_strdup(
			char *name, const char **test,
			char *(*ft_user)(const char *), char *(*ft_orig)(const char *))
{
	int		i;
	char	*user;
	char	*orig;
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
		success = (!strcmp(user, orig) && (strlen(user) == strlen(orig))) ? true : false;
		printf("%s => test: ", success ? OK : KO);
		ft_putstr_isprint(test[i], true);
		if (!success)
		{
			printf("user: ");
			ft_putstr_isprint(user, false);
			printf(" | orig: ");
			ft_putstr_isprint(orig, true);
		}
		free(user);
		free(orig);
		grade += success ? 1 : 0;
		i++;
	}
	printf("Grade: %s\n", grade == i ? SUCCESS : FAIL);
}
