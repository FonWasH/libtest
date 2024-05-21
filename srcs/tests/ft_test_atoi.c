/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:50 by juperez           #+#    #+#             */
/*   Updated: 2024/05/21 14:50:35 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_atoi_str[] = {
	"\t\n\v\f\r +00000042",
	" -42a",
	" a42",
	" -+--+42",
	"-2147483648",
	"2147483647",
	"0",
	"-00",
	"",
	"999999999999999",
	"-999999999999999",
	"9999999999999999999",
	"-9999999999999999999",
	"999999999999999999999",
	"-999999999999999999999",
	"9999999999999999999999",
	"-9999999999999999999999",
	"00000000000000000000042",
	NULL
};

static bool	ft_run_test(const char *nptr)
{
	int	user, libc;

	ft_time_function(USER_START);
	user = ft_atoi(nptr);
	ft_time_function(USER_END_LIBC_START);
	libc = atoi(nptr);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_str((char *)nptr, NULL);
		ft_result_output_int(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

bool	ft_test_atoi(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_atoi_str[i])
	{
		grade += ft_run_test(g_atoi_str[i]);
		i++;
	}
	return (grade == i);
}
