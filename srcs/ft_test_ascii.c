/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:26:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_test_ascii(
			char *name, const char *test, int (*ft_user)(int), int (*ft_orig)(int))
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
		if (strstr(name, "ft_is"))
			success = ((orig && user) || (!orig && !user)) ? true : false;
		else if (strstr(name, "ft_to"))
			success = (orig == user) ? true : false;
		printf("%s => test: ", success ? OK : KO);
		ft_putchar_isprint(test[i], true);
		if (!success)
			printf("user: %i | orig: %i\n", user, orig);
		grade += success ? 1 : 0;
		i++;
	}
	printf("Grade: %s\n", grade == i ? SUCCESS : FAIL);
}
