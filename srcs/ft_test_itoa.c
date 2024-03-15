/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:58 by juperez           #+#    #+#             */
/*   Updated: 2024/03/15 09:50:37 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_test_itoa(char *name, const char **test, char *(*ft_user)(int))
{
	int		i;
	char	*user;
	int		grade;
	bool	success;	

	printf("-- %s%s%s --\n", Y, name, X);
	if (!ft_norminette(name))
		return ;
	grade = 0;
	i = 0;
	while (test[i])
	{
		user = (*ft_user)(atoi(test[i]));
		success = (!strcmp(user, test[i])) ? true : false;
		printf("%s => test: ", success ? OK : KO);
		ft_putstr_isprint(test[i], true);
		if (!success)
		{
			printf("user: ");
			ft_putstr_isprint(user, false);
			printf(" | orig: ");
			ft_putstr_isprint(test[i], true);
		}
		free(user);
		grade += success ? 1 : 0;
		i++;
	}
	printf("Grade: %s\n", grade == i ? SUCCESS : FAIL);
}
