/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:47:10 by juperez           #+#    #+#             */
/*   Updated: 2024/03/15 09:54:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

const char	*g_atoi_tests[] = {
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

const char	*g_itoa_tests[] = {
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

const char	*g_str_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"42",
	"#",
	"",
	NULL
};

int	main(int ac, char *av[])
{
	if (ac > 1)
	{
		if (!strcmp(av[1], "all"))
		{
			ft_test_ascii("ft_isalnum", CHAR_TEST, &ft_isalnum, &isalnum);
			ft_test_ascii("ft_isalpha", CHAR_TEST, &ft_isalpha, &isalpha);
			ft_test_ascii("ft_isascii", CHAR_TEST, &ft_isascii, &isascii);
			ft_test_ascii("ft_isdigit", CHAR_TEST, &ft_isdigit, &isdigit);
			ft_test_ascii("ft_isprint", CHAR_TEST, &ft_isdigit, &isdigit);
			ft_test_ascii("ft_tolower", CHAR_TEST, &ft_tolower, &tolower);
			ft_test_ascii("ft_toupper", CHAR_TEST, &ft_toupper, &toupper);
			ft_test_strlen("ft_strlen", g_str_tests, &ft_strlen, &strlen);
			ft_test_strdup("ft_strdup", g_str_tests, &ft_strdup, &strdup);
			ft_test_atoi("ft_atoi", g_atoi_tests, &ft_atoi, &atoi);
			ft_test_itoa("ft_itoa", g_itoa_tests, &ft_itoa);
		}
		else if (!strcmp(av[1], "bonus"))
		{
			printf("WIP\n");
		}
		else if (!strcmp(av[1], "ft_isalnum"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_isalnum, &isalnum);
		else if (!strcmp(av[1], "ft_isalpha"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_isalpha, &isalpha);
		else if (!strcmp(av[1], "ft_isascii"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_isascii, &isascii);
		else if (!strcmp(av[1], "ft_isdigit"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_isdigit, &isdigit);
		else if (!strcmp(av[1], "ft_isprint"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_isprint, &isprint);
		else if (!strcmp(av[1], "ft_tolower"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_tolower, &tolower);
		else if (!strcmp(av[1], "ft_toupper"))
			ft_test_ascii(av[1], ac > 2 ? av[2] : CHAR_TEST, &ft_toupper, &toupper);
		else if (!strcmp(av[1], "ft_strlen"))
			ft_test_strlen(av[1], ac > 2 ? (const char **)(av + 2) : g_str_tests, &ft_strlen, &strlen);
		else if (!strcmp(av[1], "ft_strdup"))
			ft_test_strdup(av[1], ac > 2 ? (const char **)(av + 2) : g_str_tests, &ft_strdup, &strdup);
		else if (!strcmp(av[1], "ft_atoi"))
			ft_test_atoi(av[1], ac > 2 ? (const char **)(av + 2) : g_atoi_tests, &ft_atoi, &atoi);
		else if (!strcmp(av[1], "ft_itoa"))
			ft_test_itoa(av[1], ac > 2 ? (const char **)(av + 2) : g_atoi_tests, &ft_itoa);
		else
			printf("Invalid argument: no test for this function '%s'\n", av[1]);
	}
	else
		printf("Test requires an argument\nExample : ft_atoi\n");
	return (EXIT_SUCCESS);
}
