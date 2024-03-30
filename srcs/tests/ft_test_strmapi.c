/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:51 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 20:28:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test()
{
	char	*user;

	ft_time_function(USER_START);
	user = ft_strmapi();
	ft_time_function(USER_END);
	if (strcmp(user, e))
	{
		ft_result_input_str();
		ft_result_input_chr();
		ft_result_input_int();
		ft_result_input_sizet();
		ft_result_output_str(user, e);
		ft_result_output_chr();
		ft_result_output_int();
		ft_result_output_sizet();
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_strmapi(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while ()
	{
		grade += ft_run_test();
		i++;
	}
	return (grade == i);
}
