/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:03:35 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 18:29:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

t_presult		g_presult;
t_result		g_result;
int 			g_node_freed;

const t_ftest	g_fmandatory[] = {
	{"ft_isalpha", ft_test_ascii},
	{"ft_isdigit", ft_test_ascii},
	{"ft_isalnum", ft_test_ascii},
	{"ft_isascii", ft_test_ascii},
	{"ft_isprint", ft_test_ascii},
	{"ft_strlen", ft_test_strlen},
	{"ft_memset", ft_test_memset},
	{"ft_bzero", ft_test_bzero},
	{"ft_memcpy", ft_test_memcpy},
	{"ft_memmove", ft_test_memmove},
	{"ft_strlcpy", ft_test_strlcpy},
	{"ft_strlcat", ft_test_strlcat},
	{"ft_tolower", ft_test_ascii},
	{"ft_toupper", ft_test_ascii},
	{"ft_strchr", ft_test_strchr},
	{"ft_strrchr", ft_test_strrchr},
	{"ft_strncmp", ft_test_strncmp},
	{"ft_memchr", ft_test_memchr},
	{"ft_memcmp", ft_test_memcmp},
	{"ft_strnstr", ft_test_strnstr},
	{"ft_atoi", ft_test_atoi},
	{"ft_calloc", ft_test_calloc},
	{"ft_strdup", ft_test_strdup},
	{"ft_substr", ft_test_substr},
	{"ft_strjoin", ft_test_strjoin},
	{"ft_strtrim", ft_test_strtrim},
	{"ft_split", ft_test_split},
	{"ft_itoa", ft_test_itoa},
	{"ft_strmapi", ft_test_strmapi},
	{"ft_striteri", ft_test_striteri},
	{"ft_putchar_fd", ft_test_putchar_fd},
	{"ft_putstr_fd", ft_test_putstr_fd},
	{"ft_putendl_fd", ft_test_putendl_fd},
	{"ft_putnbr_fd", ft_test_putnbr_fd},
	{NULL, NULL}
};

const t_ftest	g_fbonus[] = {
	{"ft_lstnew_bonus", ft_test_lstnew},
	{"ft_lstadd_front_bonus", ft_test_lstadd_front},
	{"ft_lstsize_bonus", ft_test_lstsize},
	{"ft_lstlast_bonus", ft_test_lstlast},
	{"ft_lstadd_back_bonus", ft_test_lstadd_back},
	{"ft_lstdelone_bonus", ft_test_lstdelone},
	{"ft_lstclear_bonus", ft_test_lstclear},
	{"ft_lstiter_bonus", ft_test_lstiter},
	{"ft_lstmap_bonus", ft_test_lstmap},
	{NULL, NULL}
};

const char		*g_str1_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"abcdefghijklmnopqrstuvwxyz",
	"42",
	"#",
	"",
	NULL
};

const char		*g_str2_tests[] = {
	"Hello World!",
	"Hello42",
	"abcdefghijklmnopqrstuvwxyz",
	"abcdefghijklmnopqrstuvwxyzABC",
	"abc",
	"abcABC",
	"42",
	"#",
	"",
	NULL
};

const char	*g_nbr_tests[] = {
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

const char	*g_sortn_tests[] = {
	"1",
	"2",
	"3",
	"4",
	"5",
	NULL
};

const char	*g_revn_tests[] = {
	"5",
	"4",
	"3",
	"2",
	"1",
	NULL
};

const char	*g_lowa_tests[] = {
	"a",
	"b",
	"c",
	"d",
	"e",
	NULL
};

const char	*g_uppa_tests[] = {
	"A",
	"B",
	"C",
	"D",
	"E",
	NULL
};