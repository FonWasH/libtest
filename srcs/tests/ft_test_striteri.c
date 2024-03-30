/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:32:05 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 11:08:44 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test()
{
	char	*user, *expected;

	ft_time_function(USER_START);
	user = ft_();
	ft_time_function(USER_END);
	expected = ;
	if (strcmp(user, expected))
	{
		ft_result_input_str();
		ft_result_input_chr();
		ft_result_input_int();
		ft_result_input_sizet();
		ft_result_output_str(user, expected);
		ft_result_output_int();
		ft_result_output_sizet();
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_striteri(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while ()
	{

	}
	return (grade == i);
}
