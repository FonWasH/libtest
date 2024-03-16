/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:42:22 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:15:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_check_argument(char *arg, const char **test, int count)
{
	bool	match;

	match = true;
	if (!strcmp(arg, "ft_isalnum"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_isalnum, &isalnum);
	else if (!strcmp(arg, "ft_isalpha"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_isalpha, &isalpha);
	else if (!strcmp(arg, "ft_isascii"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_isascii, &isascii);
	else if (!strcmp(arg, "ft_isdigit"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_isdigit, &isdigit);
	else if (!strcmp(arg, "ft_isprint"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_isprint, &isprint);
	else if (!strcmp(arg, "ft_tolower"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_tolower, &tolower);
	else if (!strcmp(arg, "ft_toupper"))
		ft_test_ascii(arg, count ? test[0] : CHAR_TEST, &ft_toupper, &toupper);
	else if (!strcmp(arg, "ft_strlen"))
		ft_test_strlen(arg, count ? test : g_str_tests, &ft_strlen, &strlen);
	else if (!strcmp(arg, "ft_strdup"))
		ft_test_strdup(arg, count ? test : g_str_tests, &ft_strdup, &strdup);
	else if (!strcmp(arg, "ft_atoi"))
		ft_test_atoi(arg, count ? test : g_atoi_tests, &ft_atoi, &atoi);
	else if (!strcmp(arg, "ft_itoa"))
		ft_test_itoa(arg, count ? test : g_atoi_tests, &ft_itoa);
	else
		match = false;
	return (match);
}
