/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:16:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_test_strlen(
			char *name, const char **test,
			size_t (*ft_user)(const char *), size_t (*ft_orig)(const char *))
{
	int		i;
	size_t	user;
	size_t	orig;
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
			printf("user: %li | orig: %li\n", user, orig);
		grade += success ? 1 : 0;
		i++;
	}
	printf("Grade: %s\n", grade == i ? SUCCESS : FAIL);
}
