/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:49:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/16 09:15:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_all_mandatory(void)
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
