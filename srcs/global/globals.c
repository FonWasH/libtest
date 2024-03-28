/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:03:35 by juperez           #+#    #+#             */
/*   Updated: 2024/03/27 17:19:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

t_presult		g_presult;
t_result		g_result;

const char		*g_str_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"abcdefghijklmnopqrstuvwxyz",
	"42",
	"#",
	"",
	NULL
};

const char		*g_chr_tests[] = {
	"09AZaz#\n 😀",
	NULL
};

const t_ftest	g_ftest[] = {
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
//	{"ft_strchr", ft_test_strchr},
//	{"ft_strrchr", ft_test_strrchr},
//	{"ft_strncmp", ft_test_strncmp},
//	{"ft_memchr", ft_test_memchr},
//	{"ft_memcmp", ft_test_memcmp},
//	{"ft_strnstr", ft_test_strnstr},
	{"ft_atoi", ft_test_atoi},
//	{"ft_calloc", ft_test_calloc},
	{"ft_strdup", ft_test_strdup},
//	{"ft_substr", ft_test_substr},
//	{"ft_strjoin", ft_test_strjoin},
//	{"ft_strtrim", ft_test_strtrim},
//	{"ft_split", ft_test_split},
	{"ft_itoa", ft_test_itoa},
//	{"ft_strmapi", ft_test_strmapi},
//	{"ft_striteri", ft_test_striteri},
//	{"ft_putchar_fd", ft_test_putchar_fd},
//	{"ft_putstr_fd", ft_test_putstr_fd},
//	{"ft_putendl_fd", ft_test_putendl_fd},
//	{"ft_putnbr_fd", ft_test_putnbr_fd},
//	{"ft_lstnew", ft_test_lstnew},
//	{"ft_lstadd_front", ft_test_lstadd_front},
//	{"ft_lstsize", ft_test_lstsize},
//	{"ft_lstlast", ft_test_lstlast},
//	{"ft_lstadd_back", ft_test_lstadd_back},
//	{"ft_lstdelone", ft_test_lstdelone},
//	{"ft_lstclear", ft_test_lstclear},
//	{"ft_lstiter", ft_test_lstiter},
//	{"ft_lstmap", ft_test_lstmap},
	{NULL, NULL}
};
