/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:03:35 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:59:01 by juperez          ###   ########.fr       */
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

const char		*g_chr_tests[] = {
	"09AZaz#😀",
	NULL
};

const t_ftest	g_ftest[] = {
	{"ft_isalnum", ft_test_ascii},
	{"ft_isalpha", ft_test_ascii},
	{"ft_isascii", ft_test_ascii},
	{"ft_isdigit", ft_test_ascii},
	{"ft_isprint", ft_test_ascii},
	{"ft_tolower", ft_test_ascii},
	{"ft_toupper", ft_test_ascii},
	{"ft_strlen", ft_test_strlen},
	{"ft_strdup", ft_test_strdup},
	{"ft_atoi", ft_test_atoi},
	{"ft_itoa", ft_test_itoa},
	{"ft_memset", ft_test_memset},
	{"ft_bzero", ft_test_bzero},
	{"ft_memcpy", ft_test_memcpy},
	{"ft_memmove", ft_test_memmove},
	//{"ft_memchr", ft_test_memchr},
	{NULL, NULL}
};