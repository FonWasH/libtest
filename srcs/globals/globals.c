/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:03:35 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 03:19:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char		*g_atoi_tests[] = {
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
	"999999999999999999999",
	"-9999999999999999999999",
	NULL
};

const char		*g_itoa_tests[] = {
	"42",
	"-42",
	"0",
	"-2147483648",
	"2147483647",
	"-1",
	"1",
	"100",
	NULL
};

const char		*g_str_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"42",
	"#",
	"",
	NULL
};

const char		*g_char_tests[] = {
	"09AZaz#\n😀",
	NULL
};

const t_ftest	g_ftest[] = {
	{"ft_isalnum", ft_test_ascii, g_char_tests},
	{"ft_isalpha", ft_test_ascii, g_char_tests},
	{"ft_isascii", ft_test_ascii, g_char_tests},
	{"ft_isdigit", ft_test_ascii, g_char_tests},
	{"ft_isprint", ft_test_ascii, g_char_tests},
	{"ft_tolower", ft_test_ascii, g_char_tests},
	{"ft_toupper", ft_test_ascii, g_char_tests},
	{"ft_strlen", ft_test_strlen, g_str_tests},
	{"ft_strdup", ft_test_strdup, g_str_tests},
	{"ft_atoi", ft_test_atoi, g_atoi_tests},
	{"ft_itoa", ft_test_itoa, g_itoa_tests},
	{NULL, NULL, NULL}
};

const t_fascii	g_fascii[] = {
	{"ft_isalnum", ft_isalnum, isalnum, false},
	{"ft_isalpha", ft_isalpha, isalpha, false},
	{"ft_isascii", ft_isascii, isascii, false},
	{"ft_isdigit", ft_isdigit, isdigit, false},
	{"ft_isprint", ft_isprint, isprint, false},
	{"ft_tolower", ft_tolower, tolower, true},
	{"ft_toupper", ft_toupper, toupper, true},
	{NULL, NULL, NULL, false}
};
